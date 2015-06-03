#include <HeapOp.h>


class sinksort:public Heap
{
public:
	sinksort(vector<int> v):Heap(v)
	{  };
	void sink(int k,int N)
	{
		while(2*k <= N)
		{
			int j=2*k;
			if(j<N && less(j,j+1)) j++;
			if(!less(k,j))
				break;
			exch(k,j);
			k=j;
		}
	}
	void sksort()
	{
		for(int i=N/2;i>=1;i--)
		{
			sink(i,N);
		}
		while(N>1)
		{
			exch(1,N--);
			sink(1,N);
		}
	}

};


int main()
{
	int x[13]={-1,1,20,3,40,5,6,7,8,9,10,11,12};
	vector<int> v;
	for(int i=0;i<13;i++)
	{ v.push_back(x[i]); }
	sinksort myst(v);
	myst.sksort();
	print2tree(myst.gethp());

	system("pause");
	return 1;
}