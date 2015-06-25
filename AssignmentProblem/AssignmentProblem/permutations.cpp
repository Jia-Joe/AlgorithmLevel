#include <assignment.h>
void swapv(vector<int> &s,int i,int j)
{
	int t;
	t=s[i];	
	s[i]=s[j];
	s[j]=t;
}

void perm0(vector<int> s,int n,int m,int *p)
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

		for(int i=0;i<m;i++)
		{
			p[m-1]=s[i];
			if(m==1)
			{
				for(int j=mt-1;j>=0;j--)
				{
					cout<<p[j];
				}
				cout<<endl;
			}
			else
			{
				vector<int> w=s;
				vector<int>::iterator it = w.begin()+i;
				w.erase(it);
				perm0(w,n-1,m-1,p);
			}

		}
	}
}
int main()
{
	int *p=new int[120];
	vector<int> s;
	perm0(s,3,3,p);
	delete p;
	system("pause");
	return 0;
}