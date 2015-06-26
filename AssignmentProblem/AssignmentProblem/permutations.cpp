#include <assignment.h>

vector<vector<int> > perm;

void swapv(vector<int> &s,int i,int j)
{
	int t;
	t=s[i];	
	s[i]=s[j];
	s[j]=t;
}

//void perm0(vector<int> s,int n,int m,int *p)
//{
//	if(m>n)
//	{
//		cout<<"输入错误!"<<endl;
//	}
//	else
//	{
//		if(flag)
//		{
//			mt=m;
//			flag=false;
//			for(int i=1;i<=n;i++)
//			{
//				s.push_back(i);
//			}
//
//		}
//
//		for(int i=0;i<n;i++)
//		{
//			p[m-1]=s[i];
//			if(m==1)
//			{
//				for(int j=mt-1;j>=0;j--)
//				{
//					cout<<p[j];
//				}
//				cout<<endl;
//			}
//			else
//			{
//				vector<int> w=s;
//				vector<int>::iterator it = w.begin()+i;
//				w.erase(it);
//				perm0(w,n-1,m-1,p);
//			}
//
//		}
//	}
//}


vector<vector<int> >  Perm0(vector<int> s,int n,int m,int *p)
{
	if(m>n)
	{
		cout<<"输入错误!"<<endl;
	}
	else
	{
		if(flag)
		{
			mt=m;
			flag=false;
			for(int i=1;i<=n;i++)
			{
				s.push_back(i);
			}

		}

		for(int i=0;i<n;i++)
		{
			p[m-1]=s[i];
			if(m==1)
			{
				vector<int> tmp;
				for(int j=mt-1;j>=0;j--)
				{
					tmp.push_back(p[j]);
				}
				perm.push_back(tmp);
			}
			else
			{
				vector<int> w=s;
				vector<int>::iterator it = w.begin()+i;
				w.erase(it);
				Perm0(w,n-1,m-1,p);
			}

		}
		return perm;
	}
}

vector<vector<int> >  Perm(vector<int> s,int n,int m,int *p)  //排列函数封装
{
	vector<vector<int> > tot;
	flag=true;
	tot=Perm0(s,n,m,p); 
	perm.clear();
	return tot;
}


int pNum(int n,int m)
{
	if(m==0)
		return 1;
	else
	{
		int num=1;
		for(int i=0;i<m;i++)
		{num=num*(n-i);}
		return num;
	}
}


//int main()
//{
//	int n=5,m=3;
//	int k=pNum(n,m);
//	cout<<k<<endl;
//	int *p=new int[k];
//	vector<int> s;
//	Perm0(s,n,m,p);
//	delete p;
//	system("pause");
//	return 0;
//}


//int main()
//{
//
//	int m,n;
//	cout<<" 输入参与排列元素总数 N=";
//	cin>>n;	
//	cout<<" 每个排列包含元素个数 M=";
//	cin>>m;
//	int k=pNum(n,m);
//	int *p=new int[k];
//	vector<int> s;
//	vector<vector<int> > tot;
//	tot=Perm(s,n,m,p);
//	cout<<"==========================="<<k<<endl;
//	for(int i=0;i<k;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<tot[i][j];
//		}
//		cout<<endl;
//	}
//	k=pNum(n,m-1);
//	cout<<"==========================="<<k<<endl;
//	delete p;
//	system("pause");
//	return 0;
//}


//int main()
//{
//
//	int m,n;
//	cout<<" 输入参与排列元素总数 N=";
//	cin>>n;	
//	cout<<" 每个排列包含元素个数 M=";
//	cin>>m;
//	int k=pNum(n,m);
//	int *p=new int[k];
//	vector<int> s;
//	vector<vector<int> > tot;
//	tot=Perm(s,n,m,p);
//	cout<<"==========================="<<k<<endl;
//	for(int i=0;i<k;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<tot[i][j];
//		}
//		cout<<endl;
//	}
//	k=pNum(n,m-1);
//	cout<<"==========================="<<k<<endl;
//	int *pp=new int[k];
//	tot=Perm(s,n,m-1,pp);
//	for(int i=0;i<k;i++)
//	{
//		for(int j=0;j<m-1;j++)
//		{
//			cout<<tot[i][j];
//		}
//		cout<<endl;
//	}
//	delete p;
//	delete pp;
//	system("pause");
//	return 0;
//}