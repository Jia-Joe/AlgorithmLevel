#include <assignment.h>
void swapv(vector<int> &s,int i,int j)
{
	int t;
	t=s[i];	
	s[i]=s[j];
	s[j]=t;
}

void perm0(vector<int> &s,int n,int m,int *p)
{
	if(m>n)
	{
		cout<<"ÊäÈë´íÎó!"<<endl;
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

		for(int i=n-1;i>=0;i--)
		{
			p[m-1]=s[i];
			if(!s.empty())
			{
				vector<int>::iterator it = s.begin()+i;
				s.erase(it);
			}
			if(mt==n-i)
			{
				for(int j=0;j<mt;j++)
				{
					cout<<p[j];
				}
				cout<<endl;
			}
			else if(m>0)
			{
				perm0(s,n-1,m-1,p);
			}

		}
	}
}
int main()
{
	int *p=new int[24];
	vector<int> s;
	perm0(s,5,5,p);
	delete p;
	system("pause");
	return 0;
}