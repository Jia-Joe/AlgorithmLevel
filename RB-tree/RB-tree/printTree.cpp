#define NDEBUG 
#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
#include <assert.h>
#include <iomanip>

using namespace std;

int setwN=1;

void outchar(char a, int n);
void Routchar(char a, int n);

void print2tree(vector <char> s, int n) 
{
	int dpt = log((double)n) / log(2.0) + 1;
	int mid = pow(2,dpt-1);
	//输出根节点
	for (int i = 1; i<mid; i++)
	{
		cout << setw(setwN)<<' ';
	}
	int cnt = 0;
	cout << s[cnt++]<<endl;
	for (int i = dpt-1; i>0; i--)
	{
		int leafmin = pow(2, i-1);//1
		int leafstep = leafmin * 2;//2
		int leafnum = pow(2, dpt - i);//8
		vector<int> leafindex, leafindexbefore;
		//输出第一行
		outchar('|', leafstep);
		for (int ii = 1; ii < leafnum/2; ii++)
		{
			outchar('|', leafstep*2);
		}
		cout << endl;
		//输出第二行
		for (int j = 0; j < leafnum/2; j++)
		{
			outchar('-', leafmin);
			for (int k = 0; k < leafstep; k++)
			{
				cout << setw(setwN)<<'-';
			}
			for (int k = 0; k < leafstep/2; k++)
			{
				cout << setw(setwN) << ' ';
			}
		}
		cout << endl;
		//输出第三行
		outchar('|', leafmin);
		for (int ii = 1; ii < leafnum; ii++)
		{
			outchar('|', leafstep);
		}
		cout << endl;
		//输出第四行
		outchar(s[cnt++], leafmin);
		for (int ii = 1; ii < leafnum; ii++)
		{
			outchar(s[cnt++], leafstep);
		}
		cout << endl;
	}
	
}

//void recurPrint(int mid,int n)
//{
//	if(n != 0)
//	{
//		int midleft = mid;
//		int midright = mid;
//		int dp = pow(2, n - 1);
//		for (int i = 0; i < dp; i++)
//		{
//			midleft--;
//			midright++;
//			outchar('/', midleft);
//			outchar('\\', midright - midleft);
//			cout << endl;
//		}
//
//		outchar('A', midleft);
//		outchar('B', midright - midleft);
//		cout << endl;
//		recurPrint(midleft, n - 1);
//		recurPrint(midright, n - 1);
//	}
//}

void outchar(char a, int n)
{
	for (int i = 1; i<n; i++)
	{
		cout << setw(setwN) << ' ';
	}
	cout << setw(setwN)<<a;
}

//在第n个位置输出红色节点
void Routchar(char a, int n)
{
	for (int i = 1; i<n; i++)
	{
		cout << setw(setwN) << ' ';
	}
	cout << setw(setwN - 2) << '(' << a << ')';
}

int x[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
vector<int> v(15);
//int x[20]={223,12,221,33,632,7,8,921,1,11,123,13,23,1233,1,12,1234,23,12,34};
int main()
{
	int d=log((double)15)/log(2.0)+1;
	cout << setw(3) << ' ' << setw(3 - 2) << '(' << d << ')' << setw(3) << 'h' << endl;
	cout << "123456789" << endl;
	vector <char> s;
	int tot=31;
	for (int i = 0; i < tot; i++)
		s.push_back(char(i+'0'));
	cout << endl << endl;
	print2tree(s, tot);
	system("pause");
	return 1;
}

/**
0
1                               2
3               4               5               6
7       8       9       10      11      12      13      14

*/

