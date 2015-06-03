#ifndef _HEAPOP_H
#define _HEAPOP_H
#include<math.h>
#include<iostream>
#include<stack>
#include<assert.h>
#include<vector>
using namespace std;

class Heap
{
protected:

    int N;
    vector<int> hp;
	bool less(int i,int j)
	{
		return hp[i]<hp[j];
	}
    void exch(int i,int j)
	{
		int t=hp[i];
		hp[i]=hp[j];
		hp[j]=t;
	}

public:

	Heap(){};
	Heap(vector<int> hp);
    Heap(vector<int> hp,int N);

	vector<int> gethp(){return hp;}
	int getN(){return N;}

    virtual void swim(int k);
    virtual void sink(int k);
	virtual void insert(int key);
	virtual int delMax();
};
void print2tree(int s[],int n);
void print2tree(vector<int> v);


#endif