#pragma once
#include "stdafx.h"

class weightedUF
{
private:
	vector<int> id;//第i个触点属于第id[i]个分量
	int count;//分量总数
	vector<int> sz;//根节点对应的分量的大小
public:
	weightedUF(int N)
	{
		count = N;
		for (int i = 0; i < N; i++)
		{
			id.push_back(i);
			sz.push_back(1);
		}
	}
	int countGet()
	{
		return count;
	}
	bool connected(int p, int q)
	{
		return find(p) == find(q);
	}
	int find(int p)
	{
		while (p != id[p])
			p = id[p];
		return p;
	}
	void unionPQ(int p, int q)
	{
		int i = find(p);
		int j = find(q);
		if (i == j)
			return;
		if (sz[i] < sz[j])
		{
			id[i] = j;
			sz[j] += sz[i];
		}
		else
		{
			id[j] = i;
			sz[i] += sz[j];
		}
		count--;
	}
};