#pragma once
#include "stdafx.h"

class DirectedCycle
{
private:
	vector<bool> marked;
	vector<int> edgeTo;
	stack<int> cycle;
	vector<bool> onStack;
	void dfs(Digraph &G, int v)
	{
		marked[v] = true;
		onStack[v] = true;
		for (int w : *G.getAdj(v))
		{
			if (this->hasCycle())
				return;
			else if (!marked[w])
			{
				edgeTo[w] = v;
				dfs(G, w);
			}
			else if (onStack[w])
			{
				for (int x = v; x != w; x = edgeTo[x])
				{
					cycle.push(x);
				}
				cycle.push(w);
				cycle.push(v);
				return;
			}
		}
		onStack[v] = false;
	}
public:
	DirectedCycle(Digraph &G)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
			edgeTo.push_back(0);
			onStack.push_back(false);
		}
		for (int v = 0; v < G.Vget(); v++)
		{
			if (!marked[v])
			{
				dfs(G, v);
			}
		}
	}
	bool hasCycle()
	{
		return !cycle.empty();
	}
	stack<int> getCycleStack()
	{
		return cycle;
	}
};