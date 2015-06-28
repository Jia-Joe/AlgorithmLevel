// QueueingNetwork.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;

extern double a[Number][Number], b[Number], copy_a[Number][Number], copy_b[Number];    //ϵ������ʽ
extern int lenth;
extern char * x;
double u[M],X[M],P[M][M];

extern void input();    //���뷽�� 
extern void guass_all();
extern void gauss_calculate();       //����Gauss��ȥ���������δ֪����ֵ
extern void guass_all_solv();		  //Gaussȫ��Ԫ�ⷽ����
extern void solve();
void input_data();
void gauss_all_xiaoqu();      //Gaussȫ��Ԫ��ȥ��



void input_data()
{
	//cout << "Input the service rate of each facility u:" << endl;
	//for (int i = 0; i < M; i++)
	//	cin >> u[i];

	bool flag = true;
	while (flag)
	{
		flag = false;
		cout << "Input the transition probability matrix Pij:" << endl;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> P[i][j];
			}
		}
		//���Pijÿһ�и��ʺ��Ƿ�Ϊ1
		for (int i = 0; i < M; i++)
		{
			double temp = 0;
			for (int j = 0; j < M; j++)
			{
				temp += P[i][j];
			}
			if (temp != 1.0)
			{
				flag = true;
				cout<<"Input error for Pij! "<<endl;
				break;
			}

		}

	}

	for (int i = 0; i<M-1; i++)
	{

		for (int j = 0; j < M - 1; j++)
		{
			if (i != j)
				a[i][j] = u[i + 1] * P[j + 1][i + 1];
			else
				a[i][j] = u[i + 1] * P[j + 1][i + 1] - u[i + 1];
		}

	}
	for (int i = 0; i < M - 1; i++)
		b[i] =-u[0]*P[0][i+1];
}

void input1()
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
}

//��˹ȫ��Ԫ������ⷽ��
void guass_all1()
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
		int k = 0;
		for (i = 0; i<lenth; i++)   //������
		{
			for (j = 0; x[j] != 'a' + i&&j<lenth; j++);
			cout << x[j] << "=" << b[j] << endl;
			X[k++] = b[j];
		}
	}
	else
		cout << "ϵ������ʽ������,����û��Ψһ�Ľ�.\n";
	delete[] x;
}


int _tmain(int argc, _TCHAR* argv[])
{
	input1();    //���뷽�� 
	guass_all1();

	for (int i = 0; i < M; i++)
		cout << b[i];
	for (int i = 0; i < M; i++)
		cout << X[i];
	system("pause");
}