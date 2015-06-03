#define NDEBUG 
#include<math.h>
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

 extern void print2tree(int s[],int n) {
    int Depth=log((double)n)/log(2.0)+1;
	stack<int> dis;
	dis.push(1);
	int tmp=0;
	for(int i=1;i<Depth-1;i++)
	{	
		dis.push(2*dis.top());
	}
	for(int i=1;i<Depth;i++)
	{
		int d=dis.top();
		assert(d==4);
		dis.pop();
		for(int j=0;j<d-1;j++)
		{
			cout<<'\t';
		}
		int k=(int)pow(2.0,i-1);
		for(int j=0;j<k;j++)
		{
			cout<<'\t'<<s[k-1+j];
			if(j!=k-1)
			{
				for(int m=0;m<2*d-1;m++)
				{
					cout<<'	';
				}
			}
		}
		cout<<endl;
	}
	for(int i=(int)pow(2.0,Depth-1)-1;i<n;i++)
	{
		cout<<"    "<<s[i]<<'\t';
	}
	cout<<endl;
}

int x[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
//int x[20]={223,12,221,33,632,7,8,921,1,11,123,13,23,1233,1,12,1234,23,12,34};
int main()
{
//	int d=log((double)15)/log(2.0)+1;
	print2tree(x,15);
	system("pause");
	return 1;
}

/**
                                0
                1                               2
        3               4               5               6
    7       8       9       10      11      12      13      14

*/

