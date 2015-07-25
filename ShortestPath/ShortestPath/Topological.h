#pragma once
#include "stdafx.h"

#include "EdgeWeightedDigraph.h"
/********************************************************************
����DFS�Ķ�������
ǰ�򣺵ݹ�֮ǰ������������pre()
���򣺵ݹ�֮�󽫶���������post()
�����򣺵ݹ�֮�󽫶���ѹ��ջreversePost()
*********************************************************************/
class Topological
{
private:
	vector<bool> marked;
	stack<int> reversePost;
	void dfs(EdgeWeightedDigraph &G, int v)
	{
		marked[v] = true;
		for (Edge e : G.adjGet(v))
		{
			if (!marked[e.to()])
			{
				dfs(G, e.to());
			}
		}
		reversePost.push(v);
	}
public:
	Topological(EdgeWeightedDigraph &G)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
		}
		for (int v = 0; v < G.Vget() ; v++)
		{
			if (!marked[v])
				dfs(G, v);
		}
	}


	stack<int> greversePost()
	{
		return reversePost;
	}
	vector<int> gTopoSort()
	{
		stack<int> stmp = reversePost;
		vector<int> vout;
		int cs1 = stmp.size();
		for (int i = 0; i <cs1; i++)
		{
			vout.push_back(stmp.top());
			stmp.pop();
		}
		return vout;
	}
};