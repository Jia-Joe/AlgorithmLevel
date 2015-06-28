// QueueingNetwork.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <math.h>
#include <iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

extern double a[Number][Number], b[Number], copy_a[Number][Number], copy_b[Number];    //Coefficient Determinant
extern int lenth;
extern int A_y[Number];  //a [] [] increase in the horizontal column coordinates with the order

double u[M],X[M],P[M][M];

extern void input();    //Input eqution
extern void cramer();   //Cramer Algorithms for Solving Equations
extern void solve();
void input_data();



void input_data()
{

	//Input_data 

	//cout << "Input the service rate of each facility u:" << endl;
	//for (int i = 0; i < M; i++)
	//	cin >> u[i];


	//bool flag = true;
	//while (flag)
	//{
	//	flag = false;
	//	cout << "Input the transition probability matrix Pij:" << endl;
	//	for (int i = 0; i < M; i++)
	//	{
	//		for (int j = 0; j < M; j++)
	//		{
	//			cin >> P[i][j];
	//		}
	//	}
	//	//Check whether the probabilities of each row in Pij add up to 1
	//	for (int i = 0; i < M; i++)
	//	{
	//		double temp = 0;
	//		for (int j = 0; j < M; j++)
	//		{
	//			temp += P[i][j];
	//		}
	//		if (temp != 1.0)
	//		{
	//			flag = true;
	//			cout<<"Input error for Pij! "<<endl;
	//			break;
	//		}

	//	}

	//}
	lenth = M - 1;
	P[0][0] = 0.1; P[0][1] = 0.7; P[0][2] = 0.2;
	P[1][0] = 1.0;
	P[2][0] = 1.0;
	u[0] = 1.0/28; u[1] = 1.0/40; u[2] = 1.0/280;

	//Tr to the standard form of a linear equation
	for (int i = 0; i<M-1; i++)
	{

		for (int j = 0; j < M - 1; j++)
		{
			if (i != j)
			{
				a[i][j] = u[i + 1] * P[j + 1][i + 1];
			}
			else
			{
				a[i][j] = u[i + 1] * P[j + 1][i + 1] - u[i + 1];
			}

		}

	}

	for (int i = 0; i < M - 1; i++)
		b[i] =-u[0]*P[0][i+1];
	
	cout << "Solve the following equtions:" << endl;
	cout << setw(6) << a[0][0]  << setw(14)  << a[0][1] << setw(4)  << "=" << b[0] << endl;
	cout << setw(6) << a[1][0]  << setw(14)  << a[1][1] << setw(4)  << "=" << b[1] << endl;

}

void input1()
{
	lenth = M-1;
	int i, j;
	if (lenth>Number)
	{
		cout << "It is too big.\n";
		return;
	}


	//Input each equation
	for (i = 0; i<lenth; i++)
	{
		cout << "输入方程" << i + 1 << ":";
		for (j = 0; j<lenth; j++)
			cin >> a[i][j];
		cin >> b[i];
	}

	//Data backup
	for (i = 0; i<lenth; i++)
	for (j = 0; j<lenth; j++)
		copy_a[i][j] = a[i][j];
	for (i = 0; i<lenth; i++)
		copy_b[i] = b[i];
}


//Networks  with  Load  Dependent  Servers

//The load is k,and the service rate of the ith server  will have a factor ai
double ai(int i, int k)
{
	return i-0.8*exp(-k);
}

//The auxiliary  function for the ith server
double Auxfun(int i,int k)
{
	if (k == 0)
		return 1.0;
	else
	{
		double tmp=1;
		for (int j = 1; j <= k + 1; j++)
		{
			tmp = tmp*ai(i,j);
		}
		return tmp;
	}

//	return 1.0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	input_data();    
	cramer();

	//(X1, X2,... Xm)  is  a  real  positive  solution  to the eigenvector - like equations
	X[0] = 1;
	for (int i = 0; i < M; i++)
		cout << "X"<<i<<" = "<<X[i]<<endl;
	cout << endl << endl;

	//According to the paper only two columns are necessary to store the information of g(n,m)
	double gnm[N+1][2];

	//The first column
	for (int n = 0; n < N + 1; n++)
	{
		gnm[n][1] = pow(X[0], n)/Auxfun(1,n);
	}


	for (int m = 2; m <= M; m++)
	{
		int cnt0 = m % 2;
		int cnt1 = (m + 1) % 2;
		gnm[0][cnt0] = 1;
		for (int n = 1; n <= N ; n++)
		{
			double sum = 0;
			for (int k = 0; k <= n; k++)
			{
				sum += gnm[k][cnt1] * pow(X[m - 1], n - k) / Auxfun(m, n - k);
//				cout << sum << endl;
			}
			gnm[n][cnt0] = sum; 
		}
	}

	cout << "=====Values of g(n,m)=====" << endl;
	cout << setw(4) << "n" << setw(10) << "Xm-1" << setw(10) << "Xm" << endl;
	for (int i = 0; i < N + 1; i++)
	{
		cout << setw(4) << i << setw(10) << gnm[i][(M + 1) % 2] << setw(10) << gnm[i][M % 2] << endl;
	}
	cout << "==========================" << endl << endl << endl;

	system("pause");
}