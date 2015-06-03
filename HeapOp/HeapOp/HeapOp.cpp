#include <HeapOp.h>

Heap::Heap(vector<int> hp)
{
	this->hp=hp;
	this->N=hp.size()-1;
}
Heap::Heap(vector<int> hp,int N)
{
	this->hp=hp;
	this->N=N;
}

void Heap::swim(int k)
{
	while(k>1&&less(k/2,k))
	{
		exch(k/2,k);
		k=k/2;
	}
}
void Heap::sink(int k)
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


void Heap::insert(int key)
{
	this->hp.push_back(key);
	swim(++N);
}
int Heap::delMax()
{
	int max=hp[1];
	exch(1,N--);
	hp[N+1]=NULL;
	hp.pop_back();
	sink(1);

	return max;
}

int main()
{
	vector<int> v;
//	int x[12]={1,2,3,4,5,6,7,8,9,10,11,12};
	int x[12]={1,20,3,40,5,6,7,8,9,10,11,12};
	v.push_back(-1);
	for(int i=0;i<12;i++) {
		v.push_back(x[i]);
	}
	Heap myhp(v);
	print2tree(myhp.gethp());
	myhp.insert(10);
	cout<<endl<<endl;
	print2tree(myhp.gethp());
	cout<<endl<<endl;
	cout<<myhp.delMax()<<endl;
	print2tree(myhp.gethp());
	system("pause");
	return 1;
}