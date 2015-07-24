#pragma once
#include "stdafx.h"

template<class T=double>
class IndexMinPQ
{
private:
	vector<int> pq;//索引二叉堆，根节点序号为1，不为0
	vector<int> qp;//pq的逆序，qp[i]=i在pq[]中的位置,qp[pq[i]]=pq[qp[i]]=i
	//若i不在队列中，qp[i]=-1
	vector<T> keys;//有优先级之分的元素

	void swim(int k)
	{
		while (k>1 && more(k / 2, k))
		{
			exch(k,k/2);
			k = k / 2;
		}
	}
	void sink(int k)
	{
		while (2 * k <= N)
		{
			int j = 2 * k;
			if (j < N && more(j, j + 1)) j++;
			if (!more(k, j))
				break;
			exch(k, j);
			k = j;
		}
	}
	bool more(int i, int j)
	{
		return keys[pq[i]]>keys[pq[j]];
	}
	void exch(int i, int j)
	{
		int ti = pq[i],tj = pq[j];
		pq[i] = tj;
		pq[j] = ti;
		qp[ti] = j;
		qp[tj] = i;
	}

public:
	IndexMinPQ(){};
	IndexMinPQInit(int maxN)
	{
		for (int i = 0; i < maxN + 1; i++)
		{
			keys.push_back(INF);
			pq.push_back(-1);
			qp.push_back(-1);
		}
	}
	bool isEmpty()
	{
		return N == 0;
	}
	bool contains(int k)
	{
		return qp[k] != -1;
	}
	void insert(int k, T key)
	{
		N++;
		qp[k] = N;
		pq[N] = k;
		keys[k] = key;
		swim(N);
	}
	T min()
	{
		return keys[pq[1]];
	}
	int delMin()
	{
		int indexMin = pq[1];
		exch(1, N--);//第一个和最后一个交换
		sink(1);
		keys[pq[N + 1]] = -1;
		qp[pq[N + 1]] = -1;
		return indexMin;
	}
	int minIndex()
	{
		return pq[1];
	}
	int getN()
	{
		return N;
	}
	void print()
	{
		for (int i = 1; i <= N; i++)
		{
			cout << keys[pq[i]] << "--";
		}
		cout << endl;
	}
	void change(int k, T key)
	{
		keys[k] = key;
		swim(qp[k]);
		sink(qp[k]);
	}
	void deleteK(int k)
	{
		exch(k, N--);
		swim(qp[k]);
		sink(qp[k]);
		keys[pq[N + 1]] = NULL;
		qp[pq[N + 1]] = -1;
	}
};
