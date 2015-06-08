#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

int n,m;           //n——参与组合元素个数，m——每个组合中元素个数
int *p;           //存放组合元素的数组  

//void Print()                     
//{
//	for(int i=0;i<m;i++)
//	cout<<setw(1)<<char(p[i]+64);
//	cout<<setw(1)<<p[i];
//	cout<<endl;
//}


static bool flag=true;
static int mt;
vector<vector<int> >  Comb(int n,int m)   //递归求组合
{
	static vector<vector<int> > comb;
	if(m==0||m>n)
	{
		cout<<"输入错误!"<<endl;
		return comb;
	}
	else
	{
		if(flag)			//函数运行时只初始化一次
		{
			mt=m;
			flag=false;
		}
		for(int i=n;i>=m;i--)  
		{
			p[m-1]=i;
			if(m==1)
			{
				vector<int> tmp;
				for(int i=0;i<mt;i++)
				{
					cout<<setw(1)<<p[i];
					tmp.push_back(p[i]);
				}
				cout<<endl;
				comb.push_back(tmp);
			}
			else
				Comb(i-1,m-1);
		}
		return comb;
	}

}


int cNum(int n,int m)
{
	if(m==0)
		return 1;
	else
	{
		int num=1,den=1;
		for(int i=0;i<m;i++)
		{num=num*(n-i);}
		for(int i=1;i<m+1;i++)
		{den=den*i;}
		return num/den;
	}
}

int main()
{
//while(1)
//{
//	cout<<" 输入参与组合元素总数 N=";
//	cin>>n;	
//	cout<<" 每个组合包含元素个数 M=";
//	cin>>m;
//	cout<<cNum(n,m)<<endl;
//}
	cout<<" 输入参与组合元素总数 N=";
	cin>>n;	
	cout<<" 每个组合包含元素个数 M=";
	cin>>m;
	int k=cNum(n,m);
	p=new int[k];
	vector<vector<int> > tot;
	tot=Comb(n,m);
	cout<<"==========================="<<endl;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<tot[i][j];
		}
		cout<<endl;
	}
	delete p;
	system("pause");
	return 0;
}
	