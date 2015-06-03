#include <HeapOp.h>

bool Heap::less(int i,int j)
{
	return hp[i]<hp[j];
}
void Heap::exch(int i,int j)
{
    int t=hp[i];
    hp[i]=hp[j];
    hp[j]=t;
}

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
        if(j<N && less(k,k+1)) j++;
        if(!less(k,j));
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
	sink(1);
	hp[N]=NULL;
	return max;
}


#include <stdio.h>
int main()
{
	vector<int> v;
	enum{}
	v[0]=-1;v[1]='a';
	int N=12;
	Heap myhp(v,N);
	system("pause");
	return 1;
}