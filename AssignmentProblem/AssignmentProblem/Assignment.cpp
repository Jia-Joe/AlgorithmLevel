#include <assignment.h>

const int N=2;    //  Problem scale

int main()
{

	int costMat[N][N];
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			scanf("%d",&costMat[i][j]);
		}
		getchar();
	}
	cout<<endl;



	int k=pNum(N,N);
	int *p=new int[k];
	vector<vector<int> > pm;
	vector<int> s;
	pm=Perm(s,N,N,p);

	int cost=2147483647;
	int vec[4];
	for(int i=0;i<N;i++)
	{vec[i]=i+1;}

	for(int i=0;i<k;i++)
	{
		int w=0,ctmp=0;
		for(int j=0;j<N;j++)
		{
			ctmp+=costMat[w][pm[i][j]-1];
			w=w+1;			
		}
		if(ctmp<cost)
		{
			cost=ctmp;
			for(int d=0;d<N;d++)
			{
				vec[d]=pm[i][d];
			}
		}
	}
	
	cout<<"================"<<endl;
	cout<<"Minimum Cost: "<<cost<<endl;
	//for(int i=0;i<N;i++) {
	//	cout<<vec[i];
	//}
	cout<<"================"<<endl;


	int outMat[N][N]={0};
	int outi=0;
	for(int i=0;i<N;i++) {
		outMat[outi][vec[i]-1]=1;
		outi++;
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cout<<setw(4)<<outMat[i][j];
		}
		cout<<endl;
	}

	delete p;
	system("pause");
	return 0;
}