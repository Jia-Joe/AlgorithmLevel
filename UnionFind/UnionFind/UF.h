#pragma once
#include "stdafx.h"

class UFquickunion
{
private:
	vector<int> id;//��i���������ڵ�id[i]������
	int count;//��������
public:
	UFquickunion(int N)
	{
		count = N;
		for (int i = 0; i < N; i++)
		{
			id.push_back(i);
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
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot)
			return;
		id[pRoot] = qRoot;
		count--;
	}
};

class UFquickfind
{
private:
	vector<int> id;//��i���������ڵ�id[i]������
	int count;//��������
public:
	UFquickfind(int N)
	{
		count = N;
		for (int i = 0; i < N; i++)
		{
			id.push_back(i);
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
		return id[p];
	}
	void unionPQ(int p, int q)
	{
		int pID = find(p);
		int qID = find(q);
		if (pID == qID)
			return;
		//��p�ķ���������Ϊq������
		for (int i = 0; i < id.size(); i++)
		{
			if (id[i] == pID)
				id[i] = qID;
		}
		count--;
	}
};