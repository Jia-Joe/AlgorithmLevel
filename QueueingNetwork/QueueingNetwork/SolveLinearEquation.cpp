#include "stdafx.h"
using namespace std;

//Reference---http://bbs.csdn.net/topics/380095940


#include <math.h>
#include <iostream>
#include<iomanip>
#include<cstdlib>
//解线性方程组

//----------------------------------------------全局变量定义区

double a[Number][Number], b[Number], copy_a[Number][Number], copy_b[Number];    //系数行列式
int A_y[Number];        //a[][]中随着横坐标增加列坐标的排列顺序,如a[0][0],a[1][2],a[2][1]...则A_y[]={0,2,1...};
int  lenth,copy_lenth;          //方程的个数
double a_sum;         //计算行列式的值
char * x;          //未知量a,b,c的载体
extern double X[M];

//----------------------------------------------函数声明区
void input();         //输入方程组
void print_menu();        //打印主菜单
int  choose();         //输入选择
void cramer();         //Cramer算法解方程组
void gauss_row();        //Gauss列主元解方程组
void guass_all();        //Gauss全主元解方程组
void Doolittle();        //用Doolittle算法解方程组
int  Doolittle_check(double  a[][Number], double  b[Number]); //判断是否行列式>0,若是,调整为顺序主子式全>0
void xiaoqu_u_l();        //将行列式Doolittle分解
void calculate_u_l();       //计算Doolittle结果 
double & calculate_A(int n, int m);    //计算行列式
double quanpailie_A();       //根据列坐标的排列计算的值,如A_y[]={0,2,1},得sum=a[0][ A_y[0] ] * a[1][ A_y[1] ] * a[2][ A_y[2] ]=a[0][0]*a[1][2]*a[2][1];
void exchange(int m, int i);      //交换A_y[m],A_y[i]
void exchange_lie(int j);      //交换a[][j]与b[];
void exchange_hang(int m, int n);    //分别交换a[][]和b[]中的m与n两行
void gauss_row_xiaoqu();      //Gauss列主元消去法
void gauss_all_xiaoqu();      //Gauss全主元消去法
void gauss_calculate();       //根据Gauss消去法结果计算未知量的值
void exchange_a_lie(int m, int n);    //交换a[][]中的m和n列
void exchange_x(int m, int n);     //交换x[]中的x[m]和x[n]
void recovery();        //恢复数据

//主函数
void main1()
{
	int flag = 1;
	input();    //输入方程 
	while (flag)
	{
		print_menu();  //打印主菜单

		flag = choose();  //选择解答方式
		for (int i = 0; i < 2; i++)
			cout << b[i];
	}

}

void main2()
{
	input();    //输入方程 
	guass_all();

	for (int i = 0; i < lenth; i++)
			cout << b[i];
		system("pause");

}
//函数定义区
void print_menu()
{
	system("cls");
	cout << "------------方程系数和常数矩阵表示如下:\n";
	for (int j = 0; j<lenth; j++)
		cout << "系数" << j + 1 << "   ";
	cout << "\t常数";
	cout << endl;
	for (int i = 0; i<lenth; i++)
	{
		for (int j = 0; j<lenth; j++)
			cout << setw(8) << setiosflags(ios::left) << a[i][j];
		cout << "\t" << b[i] << endl;
	}
	cout << "-----------请选择方程解答的方案----------";
	cout << "\n           1. 克拉默(Cramer)法则";
	cout << "\n           2. Gauss列主元消去法";
	cout << "\n           3. Gauss全主元消去法";
	cout << "\n           4. Doolittle分解法";
	cout << "\n           5. 退出";
	cout << "\n           输入你的选择:";

}

void input()
{
	lenth = M;
	int i, j;
	if (lenth>Number)
	{
		cout << "It is too big.\n";
		return;
	}
	x = new char[lenth];
	for (i = 0; i<lenth; i++)
		x[i] = 'a' + i;

	//输入方程矩阵
	//提示如何输入
	cout << "====================================================\n";
	cout << "请在每个方程里输入" << lenth << "系数和一个常数:\n";
	cout << "例：\n方程:a";
	for (i = 1; i<lenth; i++)
	{
		cout << "+" << i + 1 << x[i];
	}
	cout << "=10\n";
	cout << "应输入:";
	for (i = 0; i<lenth; i++)
		cout << i + 1 << " ";
	cout << "10\n";
	cout << "==============================\n";


	//输入每个方程
	for (i = 0; i<lenth; i++)
	{
		cout << "输入方程" << i + 1 << ":";
		for (j = 0; j<lenth; j++)
			cin >> a[i][j];
		cin >> b[i];
	}

	//备份数据
	for (i = 0; i<lenth; i++)
	for (j = 0; j<lenth; j++)
		copy_a[i][j] = a[i][j];
	for (i = 0; i<lenth; i++)
		copy_b[i] = b[i];
	copy_lenth = lenth;
}


//输入选择
int choose()
{
	int choice; char ch;
	cin >> choice;
	switch (choice)
	{
	case 1:cramer(); break;
	case 2:gauss_row(); break;
	case 3:guass_all(); break;
	case 4:Doolittle(); break;
	case 5:return 0;
	default:cout << "输入错误,请重新输入:";
		choose();
		break;
	}
	cout << "\n是否换种方法求解(Y/N):";
	cin >> ch;
	if (ch == 'n' || ch == 'N') return 0;
	recovery();
	cout << "\n\n\n";
	return 1;

}


//用克拉默法则求解方程.
void cramer()
{
	int i, j; double sum, sum_x; char ch;
	//令第i行的列坐标为i
//	cout << "用克拉默(Cramer)法则结果如下:\n";

	for (i = 0; i<lenth; i++)
		A_y[i] = i;
	sum = calculate_A(lenth, 0);
	if (sum != 0)
	{
//		cout << "系数行列式不为零,方程有唯一的解:";
		for (i = 0; i<lenth; i++)
		{
			ch = 'a' + i;
			a_sum = 0;
			for (j = 0; j<lenth; j++)
				A_y[j] = j;
			exchange_lie(i);
			sum_x = calculate_A(lenth, 0);
			X[i + 1] = sum_x / sum;
//			cout << endl << ch << "=" << X[i + 1];
			exchange_lie(i);
		}
	}
	else
	{
		cout << "系数行列式等于零,方程没有唯一的解.";
	}
	cout << "\n";
}


double & calculate_A(int n, int m)   //计算行列式
{
	int i;
	if (n == 1) {
		a_sum += quanpailie_A();
	}
	else{
		for (i = 0; i<n; i++)
		{
			exchange(m, m + i);
			calculate_A(n - 1, m + 1);
			exchange(m, m + i);
		}
	}
	return a_sum;
}

double quanpailie_A()  //计算行列式中一种全排列的值
{
	int i, j, l;
	double sum = 0, p;
	for (i = 0, l = 0; i<lenth; i++)
	for (j = 0; A_y[j] != i&&j<lenth; j++)
	if (A_y[j]>i) l++;
	for (p = 1, i = 0; i<lenth; i++)
		p *= a[i][A_y[i]];
	sum += p*((l % 2 == 0) ? (1) : (-1));
	return sum;
}


//高斯列主元排列求解方程
void gauss_row()
{
	int i, j;
	gauss_row_xiaoqu();   //用高斯列主元消区法将系数矩阵变成一个上三角矩阵


	for (i = 0; i<lenth; i++)
	{
		for (j = 0; j<lenth; j++)
			cout << setw(10) << setprecision(5) << a[i][j];
		cout << setw(10) << b[i] << endl;
	}

	if (a[lenth - 1][lenth - 1] != 0)
	{

		cout << "系数行列式不为零,方程有唯一的解：\n";
		gauss_calculate();
		for (i = 0; i<lenth; i++)   //输出结果
		{
			cout << x[i] << "=" << b[i] << "\n";
		}
	}
	else
		cout << "系数行列式等于零,方程没有唯一的解.\n";
}


void gauss_row_xiaoqu()   //高斯列主元消去法
{
	int i, j, k, maxi; double lik;
	cout << "用Gauss列主元消去法结果如下:\n";
	for (k = 0; k<lenth - 1; k++)
	{
		j = k;
		for (maxi = i = k; i<lenth; i++)
		if (a[i][j]>a[maxi][j]) maxi = i;
		if (maxi != k)
			exchange_hang(k, maxi);//


		for (i = k + 1; i<lenth; i++)
		{
			lik = a[i][k] / a[k][k];
			for (j = k; j<lenth; j++)
				a[i][j] = a[i][j] - a[k][j] * lik;
			b[i] = b[i] - b[k] * lik;
		}
	}
}

//高斯全主元排列求解方程
void guass_all()
{
	int i, j;
	gauss_all_xiaoqu();
	for (i = 0; i<lenth; i++)
	{
		for (j = 0; j<lenth; j++)
			cout << setw(10) << setprecision(5) << a[i][j];
		cout << setw(10) << b[i] << endl;
	}
	if (a[lenth - 1][lenth - 1] != 0)
	{

		cout << "系数行列式不为零,方程有唯一的解：\n";
		gauss_calculate();

		for (i = 0; i<lenth; i++)   //输出结果
		{
			for (j = 0; x[j] != 'a' + i&&j<lenth; j++);


			cout << x[j] << "=" << b[j] << endl;
		}
	}
	else
		cout << "系数行列式等于零,方程没有唯一的解.\n";
}


void gauss_all_xiaoqu()   //Gauss全主元消去法
{
	int i, j, k, maxi, maxj; double lik;
	cout << "用Gauss全主元消去法结果如下:\n";

	for (k = 0; k<lenth - 1; k++)
	{

		for (maxi = maxj = i = k; i<lenth; i++)
		{
			for (j = k; j<lenth; j++)
			if (a[i][j]>a[maxi][maxj])
			{
				maxi = i;
				maxj = j;
			}

		}
		if (maxi != k)
			exchange_hang(k, maxi);
		if (maxj != k)
		{
			exchange_a_lie(maxj, k);    //交换两列
			exchange_x(maxj, k);

		}

		for (i = k + 1; i<lenth; i++)
		{
			lik = a[i][k] / a[k][k];
			for (j = k; j<lenth; j++)
				a[i][j] = a[i][j] - a[k][j] * lik;
			b[i] = b[i] - b[k] * lik;
		}
	}
}


void gauss_calculate()    //高斯消去法以后计算未知量的结果
{
	int i, j; double sum_ax;
	b[lenth - 1] = b[lenth - 1] / a[lenth - 1][lenth - 1];
	for (i = lenth - 2; i >= 0; i--)
	{
		for (j = i + 1, sum_ax = 0; j<lenth; j++)
			sum_ax += a[i][j] * b[j];
		b[i] = (b[i] - sum_ax) / a[i][i];
	}
}

//Doolittle消去法计算方程组
void Doolittle()
{
	double temp_a[Number][Number], temp_b[Number]; int i, j, flag;
	for (i = 0; i<lenth; i++)
	for (j = 0; j<lenth; j++)
		temp_a[i][j] = a[i][j];
	flag = Doolittle_check(temp_a, temp_b);
	if (flag == 0) cout << "\n行列式为零.无法用Doolittle求解.";
	xiaoqu_u_l();
	calculate_u_l();
	cout << "用Doolittle方法求得结果如下:\n";
	for (i = 0; i<lenth; i++)   //输出结果
	{
		for (j = 0; x[j] != 'a' + i&&j<lenth; j++);


		cout << x[j] << "=" << b[j] << endl;
	}

}

void calculate_u_l()  //计算Doolittle结果
{
	int i, j; double sum_ax = 0;
	for (i = 0; i<lenth; i++)
	{
		for (j = 0, sum_ax = 0; j<i; j++)
			sum_ax += a[i][j] * b[j];
		b[i] = b[i] - sum_ax;
	}

	for (i = lenth - 1; i >= 0; i--)
	{
		for (j = i + 1, sum_ax = 0; j<lenth; j++)
			sum_ax += a[i][j] * b[j];
		b[i] = (b[i] - sum_ax) / a[i][i];
	}

}
void xiaoqu_u_l()   //将行列式按Doolittle分解

{
	int i, j, n, k; double temp;
	for (i = 1, j = 0; i<lenth; i++)
		a[i][j] = a[i][j] / a[0][0];
	for (n = 1; n<lenth; n++)
	{  //求第n+1层的上三角矩阵部分即U
		for (j = n; j<lenth; j++)
		{
			for (k = 0, temp = 0; k<n; k++)
				temp += a[n][k] * a[k][j];
			a[n][j] -= temp;
		}
		for (i = n + 1; i<lenth; i++)  //求第n+1层的下三角矩阵部分即L
		{
			for (k = 0, temp = 0; k<n; k++)
				temp += a[i][k] * a[k][n];
			a[i][n] = (a[i][n] - temp) / a[n][n];
		}
	}
}

int Doolittle_check(double  temp_a[][Number], double  temp_b[Number])  //若行列式不为零,将系数矩阵调整为顺序主子式大于零
{
	int i, j, k, maxi; double lik, temp;

	for (k = 0; k<lenth - 1; k++)
	{
		j = k;
		for (maxi = i = k; i<lenth; i++)
		if (temp_a[i][j]>temp_a[maxi][j]) maxi = i;
		if (maxi != k)
		{
			exchange_hang(k, maxi);
			for (j = 0; j<lenth; j++)
			{
				temp = temp_a[k][j];
				temp_a[k][j] = temp_a[maxi][j];
				temp_a[maxi][j] = temp;
			}
		}
		for (i = k + 1; i<lenth; i++)
		{
			lik = temp_a[i][k] / temp_a[k][k];
			for (j = k; j<lenth; j++)
				temp_a[i][j] = temp_a[i][j] - temp_a[k][j] * lik;
			temp_b[i] = temp_b[i] - temp_b[k] * lik;
		}
	}

	if (temp_a[lenth - 1][lenth - 1] == 0)  return 0;
	return 1;
}


void exchange_hang(int m, int n)  //交换a[][]中和b[]两行
{
	int j; double temp;
	for (j = 0; j<lenth; j++)
	{
		temp = a[m][j];
		a[m][j] = a[n][j];
		a[n][j] = temp;

	}
	temp = b[m];
	b[m] = b[n];
	b[n] = temp;
}


void exchange(int m, int i)  //交换A_y[m],A_y[i]
{
	int temp;
	temp = A_y[m];
	A_y[m] = A_y[i];
	A_y[i] = temp;
}

void exchange_lie(int j)  //交换未知量b[]和第i列
{
	double temp; int i;
	for (i = 0; i<lenth; i++)
	{
		temp = a[i][j];
		a[i][j] = b[i];
		b[i] = temp;
	}
}


void exchange_a_lie(int m, int n)   //交换a[]中的两列
{
	double temp; int i;
	for (i = 0; i<lenth; i++)
	{
		temp = a[i][m];
		a[i][m] = a[i][n];
		a[i][n] = temp;
	}
}


void exchange_x(int m, int n)    //交换未知量x[m]与x[n]
{
	char temp;
	temp = x[m];
	x[m] = x[n];
	x[n] = temp;
}

void recovery()        //用其中一种方法求解后恢复数据以便用其他方法求解
{
	for (int i = 0; i<lenth; i++)
	for (int j = 0; j<lenth; j++)
		a[i][j] = copy_a[i][j];
	for (int i = 0; i<lenth; i++)
		b[i] = copy_b[i];
	for (int i = 0; i<lenth; i++)
		x[i] = 'a' + i;
	a_sum = 0;
//	lenth = copy_lenth;
}