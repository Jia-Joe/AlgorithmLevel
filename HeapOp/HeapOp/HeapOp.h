#ifndef _HEAPOP_H
#define _HEAPOP_H

#include<vector>
using namespace std;
class Heap
{
    private:

    int N;
    vector<int> hp;
    bool less(int i,int j);
    void exch(int i,int j);

    public:

	Heap(vector<int> hp);
    Heap(vector<int> hp,int N);
    void swim(int k);
    void sink(int k);
	void insert(int key);
	int delMax();
}


#endif