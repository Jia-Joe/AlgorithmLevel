#pragma once
#include "stdafx.h"

/********************************************************************
����DFS�Ķ�������
ǰ�򣺵ݹ�֮ǰ������������pre()
���򣺵ݹ�֮�󽫶���������post()
����򣺵ݹ�֮�󽫶���ѹ��ջreversePost()
*********************************************************************/
class DepthFirstOrder
{
private:
	vector<bool> marked;
	queue<int> pre;
	queue<int> post;
	stack<int> reversePost;
	void dfs(Digraph &G, int v)
	{
		pre.push(v);
		marked[v] = true;
		for (int w : *G.getAdj(v))
		{
			if (!marked[w])
			{
				dfs(G, w);
			}
		}
		post.push(v);
		reversePost.push(v);
	}
public:
	DepthFirstOrder(Digraph &G)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
		}
		for (int v = 0; v < G.Vget(); v++)
		{
			if (!marked[v])
				dfs(G, v);
		}
	}

	queue<int> gpre()
	{
		return pre;
	}
	queue<int> gpost()
	{
		return post;
	}
	stack<int> greversePost()
	{
		return reversePost;
	}
};