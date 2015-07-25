#pragma once
#include "stdafx.h"

#include "EdgeWeightedDigraph.h"

class FindCycle
{
private:
	vector<bool> marked;
	vector<int> edgeTo;
	stack<int> cycle;
	vector<bool> onStack;
	void dfs(EdgeWeightedDigraph &G, int v)
	{
		marked[v] = true;
		onStack[v] = true;
		for (Edge e : G.adjGet(v))
		{
			int w = e.to();
			if (this->hasCycle())
				cout<<"---"<<endl;
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
				//cycle.push(v);
				return;
			}
		}
		onStack[v] = false;
	}
public:
	FindCycle(EdgeWeightedDigraph &G)
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
	stack<int> getcycle()
	{
		return cycle;
	}
	vector<int> getCycle()
	{
		vector<int> cyc;
		stack<int> st=cycle;
		int sz = cycle.size();
		for (int i = 0; i < sz; i++)
		{
			cyc.push_back(st.top());
			st.pop();
		}
		return cyc;
	}
};