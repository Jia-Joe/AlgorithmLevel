#pragma once
#include "stdafx.h"

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