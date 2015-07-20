#pragma once
#include "stdafx.h"

/********************************************************************
Kosaraju Algorithm:������ͼ��Ѱ����ͨ����
1.Digraphȡreverse
2.DepthFirstOrder��������
3.��˳����ʶ���
*********************************************************************/

class SCC
{
private:
	vector<bool> marked;
	vector<int> id;
	int count=0;
	void dfs(Digraph G, int v)
	{
		marked[v] = true;
		id[v] = count;
		for (int w : *G.getAdj(v))
		{
			dfs(G, w);
		}
	}
public:
	SCC(Digraph G)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
			id.push_back(0);
		}
		Digraph Gr = G.reverse();
		DepthFirstOrder ord(Gr);
		for (int s : ord.gTopoSort())
		{
			if (!marked[s])
			{
				dfs(G, s);
				count++;
			}
		}
	}
	bool stronglyConnected(int v, int w)
	{
		return id[v] == id[w];
	}
	int countget()//ǿ��ͨ����������
	{
		return count;
	}
	int idget(int v)//�ж϶���v�����ĸ�ǿ��ͨ����
	{
		return id[v];
	}
};