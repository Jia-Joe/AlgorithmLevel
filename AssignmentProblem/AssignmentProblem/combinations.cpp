#include <assignment.h>

//n�����������Ԫ�ظ���
//m����ÿ�������Ԫ�ظ���
//p����������Ԫ�ص�����
static bool flag=true;
static int mt;
vector<vector<int> >  Comb0(int n,int m,int *p)   //�ݹ������, 
{
	static vector<vector<int> > comb;
	if(m==0||m>n)
	{
		cout<<"�������!"<<endl;
		return comb;
	}
	else
	{
		if(flag)			//��������ʱֻ��ʼ��һ��
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
				Comb0(i-1,m-1,p);
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

vector<vector<int> >  Comb(int n,int m,int *p)  //ȫ��Ϻ�����װ
{
	vector<vector<int> > tot;
	flag=true;
	return Comb0(n,m,p); 
}

//int main()
//{
////while(1)
////{
////	cout<<" ����������Ԫ������ N=";
////	cin>>n;	
////	cout<<" ÿ����ϰ���Ԫ�ظ��� M=";
////	cin>>m;
////	cout<<cNum(n,m)<<endl;
////}
//	int m,n;
//	cout<<" ����������Ԫ������ N=";
//	cin>>n;	
//	cout<<" ÿ����ϰ���Ԫ�ظ��� M=";
//	cin>>m;
//	int k=cNum(n,m);
//	int *p=new int[k];
//	vector<vector<int> > tot;
//	tot=Comb(n,m,p);
//	cout<<"==========================="<<endl;
//	for(int i=0;i<k;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<tot[i][j];
//		}
//		cout<<endl;
//	}
//	tot=Comb(n,m+1,p);
//	delete p;
//	system("pause");
//	return 0;
//}
	