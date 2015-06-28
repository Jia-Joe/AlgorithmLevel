#include "stdafx.h"
using namespace std;

//Reference---http://bbs.csdn.net/topics/380095940


#include <math.h>
#include <iostream>
#include<iomanip>
#include<cstdlib>
//�����Է�����

//----------------------------------------------ȫ�ֱ���������

double a[Number][Number], b[Number], copy_a[Number][Number], copy_b[Number];    //ϵ������ʽ
int A_y[Number];        //a[][]�����ź��������������������˳��,��a[0][0],a[1][2],a[2][1]...��A_y[]={0,2,1...};
int  lenth,copy_lenth;          //���̵ĸ���
double a_sum;         //��������ʽ��ֵ
char * x;          //δ֪��a,b,c������
extern double X[M];

//----------------------------------------------����������
void input();         //���뷽����
void print_menu();        //��ӡ���˵�
int  choose();         //����ѡ��
void cramer();         //Cramer�㷨�ⷽ����
void gauss_row();        //Gauss����Ԫ�ⷽ����
void guass_all();        //Gaussȫ��Ԫ�ⷽ����
void Doolittle();        //��Doolittle�㷨�ⷽ����
int  Doolittle_check(double  a[][Number], double  b[Number]); //�ж��Ƿ�����ʽ>0,����,����Ϊ˳������ʽȫ>0
void xiaoqu_u_l();        //������ʽDoolittle�ֽ�
void calculate_u_l();       //����Doolittle��� 
double & calculate_A(int n, int m);    //��������ʽ
double quanpailie_A();       //��������������м����ֵ,��A_y[]={0,2,1},��sum=a[0][ A_y[0] ] * a[1][ A_y[1] ] * a[2][ A_y[2] ]=a[0][0]*a[1][2]*a[2][1];
void exchange(int m, int i);      //����A_y[m],A_y[i]
void exchange_lie(int j);      //����a[][j]��b[];
void exchange_hang(int m, int n);    //�ֱ𽻻�a[][]��b[]�е�m��n����
void gauss_row_xiaoqu();      //Gauss����Ԫ��ȥ��
void gauss_all_xiaoqu();      //Gaussȫ��Ԫ��ȥ��
void gauss_calculate();       //����Gauss��ȥ���������δ֪����ֵ
void exchange_a_lie(int m, int n);    //����a[][]�е�m��n��
void exchange_x(int m, int n);     //����x[]�е�x[m]��x[n]
void recovery();        //�ָ�����

//������
void main1()
{
	int flag = 1;
	input();    //���뷽�� 
	while (flag)
	{
		print_menu();  //��ӡ���˵�

		flag = choose();  //ѡ����ʽ
		for (int i = 0; i < 2; i++)
			cout << b[i];
	}

}

void main2()
{
	input();    //���뷽�� 
	guass_all();

	for (int i = 0; i < lenth; i++)
			cout << b[i];
		system("pause");

}
//����������
void print_menu()
{
	system("cls");
	cout << "------------����ϵ���ͳ��������ʾ����:\n";
	for (int j = 0; j<lenth; j++)
		cout << "ϵ��" << j + 1 << "   ";
	cout << "\t����";
	cout << endl;
	for (int i = 0; i<lenth; i++)
	{
		for (int j = 0; j<lenth; j++)
			cout << setw(8) << setiosflags(ios::left) << a[i][j];
		cout << "\t" << b[i] << endl;
	}
	cout << "-----------��ѡ�񷽳̽��ķ���----------";
	cout << "\n           1. ����Ĭ(Cramer)����";
	cout << "\n           2. Gauss����Ԫ��ȥ��";
	cout << "\n           3. Gaussȫ��Ԫ��ȥ��";
	cout << "\n           4. Doolittle�ֽⷨ";
	cout << "\n           5. �˳�";
	cout << "\n           �������ѡ��:";

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

	//���뷽�̾���
	//��ʾ�������
	cout << "====================================================\n";
	cout << "����ÿ������������" << lenth << "ϵ����һ������:\n";
	cout << "����\n����:a";
	for (i = 1; i<lenth; i++)
	{
		cout << "+" << i + 1 << x[i];
	}
	cout << "=10\n";
	cout << "Ӧ����:";
	for (i = 0; i<lenth; i++)
		cout << i + 1 << " ";
	cout << "10\n";
	cout << "==============================\n";


	//����ÿ������
	for (i = 0; i<lenth; i++)
	{
		cout << "���뷽��" << i + 1 << ":";
		for (j = 0; j<lenth; j++)
			cin >> a[i][j];
		cin >> b[i];
	}

	//��������
	for (i = 0; i<lenth; i++)
	for (j = 0; j<lenth; j++)
		copy_a[i][j] = a[i][j];
	for (i = 0; i<lenth; i++)
		copy_b[i] = b[i];
	copy_lenth = lenth;
}


//����ѡ��
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
	default:cout << "�������,����������:";
		choose();
		break;
	}
	cout << "\n�Ƿ��ַ������(Y/N):";
	cin >> ch;
	if (ch == 'n' || ch == 'N') return 0;
	recovery();
	cout << "\n\n\n";
	return 1;

}


//�ÿ���Ĭ������ⷽ��.
void cramer()
{
	int i, j; double sum, sum_x; char ch;
	//���i�е�������Ϊi
//	cout << "�ÿ���Ĭ(Cramer)����������:\n";

	for (i = 0; i<lenth; i++)
		A_y[i] = i;
	sum = calculate_A(lenth, 0);
	if (sum != 0)
	{
//		cout << "ϵ������ʽ��Ϊ��,������Ψһ�Ľ�:";
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
		cout << "ϵ������ʽ������,����û��Ψһ�Ľ�.";
	}
	cout << "\n";
}


double & calculate_A(int n, int m)   //��������ʽ
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

double quanpailie_A()  //��������ʽ��һ��ȫ���е�ֵ
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


//��˹����Ԫ������ⷽ��
void gauss_row()
{
	int i, j;
	gauss_row_xiaoqu();   //�ø�˹����Ԫ��������ϵ��������һ�������Ǿ���


	for (i = 0; i<lenth; i++)
	{
		for (j = 0; j<lenth; j++)
			cout << setw(10) << setprecision(5) << a[i][j];
		cout << setw(10) << b[i] << endl;
	}

	if (a[lenth - 1][lenth - 1] != 0)
	{

		cout << "ϵ������ʽ��Ϊ��,������Ψһ�Ľ⣺\n";
		gauss_calculate();
		for (i = 0; i<lenth; i++)   //������
		{
			cout << x[i] << "=" << b[i] << "\n";
		}
	}
	else
		cout << "ϵ������ʽ������,����û��Ψһ�Ľ�.\n";
}


void gauss_row_xiaoqu()   //��˹����Ԫ��ȥ��
{
	int i, j, k, maxi; double lik;
	cout << "��Gauss����Ԫ��ȥ���������:\n";
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

//��˹ȫ��Ԫ������ⷽ��
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

		cout << "ϵ������ʽ��Ϊ��,������Ψһ�Ľ⣺\n";
		gauss_calculate();

		for (i = 0; i<lenth; i++)   //������
		{
			for (j = 0; x[j] != 'a' + i&&j<lenth; j++);


			cout << x[j] << "=" << b[j] << endl;
		}
	}
	else
		cout << "ϵ������ʽ������,����û��Ψһ�Ľ�.\n";
}


void gauss_all_xiaoqu()   //Gaussȫ��Ԫ��ȥ��
{
	int i, j, k, maxi, maxj; double lik;
	cout << "��Gaussȫ��Ԫ��ȥ���������:\n";

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
			exchange_a_lie(maxj, k);    //��������
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


void gauss_calculate()    //��˹��ȥ���Ժ����δ֪���Ľ��
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

//Doolittle��ȥ�����㷽����
void Doolittle()
{
	double temp_a[Number][Number], temp_b[Number]; int i, j, flag;
	for (i = 0; i<lenth; i++)
	for (j = 0; j<lenth; j++)
		temp_a[i][j] = a[i][j];
	flag = Doolittle_check(temp_a, temp_b);
	if (flag == 0) cout << "\n����ʽΪ��.�޷���Doolittle���.";
	xiaoqu_u_l();
	calculate_u_l();
	cout << "��Doolittle������ý������:\n";
	for (i = 0; i<lenth; i++)   //������
	{
		for (j = 0; x[j] != 'a' + i&&j<lenth; j++);


		cout << x[j] << "=" << b[j] << endl;
	}

}

void calculate_u_l()  //����Doolittle���
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
void xiaoqu_u_l()   //������ʽ��Doolittle�ֽ�

{
	int i, j, n, k; double temp;
	for (i = 1, j = 0; i<lenth; i++)
		a[i][j] = a[i][j] / a[0][0];
	for (n = 1; n<lenth; n++)
	{  //���n+1��������Ǿ��󲿷ּ�U
		for (j = n; j<lenth; j++)
		{
			for (k = 0, temp = 0; k<n; k++)
				temp += a[n][k] * a[k][j];
			a[n][j] -= temp;
		}
		for (i = n + 1; i<lenth; i++)  //���n+1��������Ǿ��󲿷ּ�L
		{
			for (k = 0, temp = 0; k<n; k++)
				temp += a[i][k] * a[k][n];
			a[i][n] = (a[i][n] - temp) / a[n][n];
		}
	}
}

int Doolittle_check(double  temp_a[][Number], double  temp_b[Number])  //������ʽ��Ϊ��,��ϵ���������Ϊ˳������ʽ������
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


void exchange_hang(int m, int n)  //����a[][]�к�b[]����
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


void exchange(int m, int i)  //����A_y[m],A_y[i]
{
	int temp;
	temp = A_y[m];
	A_y[m] = A_y[i];
	A_y[i] = temp;
}

void exchange_lie(int j)  //����δ֪��b[]�͵�i��
{
	double temp; int i;
	for (i = 0; i<lenth; i++)
	{
		temp = a[i][j];
		a[i][j] = b[i];
		b[i] = temp;
	}
}


void exchange_a_lie(int m, int n)   //����a[]�е�����
{
	double temp; int i;
	for (i = 0; i<lenth; i++)
	{
		temp = a[i][m];
		a[i][m] = a[i][n];
		a[i][n] = temp;
	}
}


void exchange_x(int m, int n)    //����δ֪��x[m]��x[n]
{
	char temp;
	temp = x[m];
	x[m] = x[n];
	x[n] = temp;
}

void recovery()        //������һ�ַ�������ָ������Ա��������������
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