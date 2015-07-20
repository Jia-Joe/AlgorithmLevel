#pragma once
#include "stdafx.h"

/********************************************************************
基于DFS的顶点排序：
前序：递归之前将顶点加入队列pre()
后序：递归之后将顶点加入队列post()
逆后序：递归之后将顶点压入栈reversePost()
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