#pragma once
#include "stdafx.h"


class Graph
{
private:
	int V;
	int E;
	vector<vector<int> *> adj;
	void cinEdge()
	{
		int Enum;
		cin >> Enum;
		for (int i = 0; i < Enum; i++)
		{
			int v, w;
			while (1)
			{
				cin >> v >> w;
				if (v < V&&w < V)
					break;
				else
					cout << "输入超出范围，请重新输入顶点对：" << endl;
			}

			addEdge(v, w);
		}
	}
public:
	Graph(int V)
	{
		this->V = V;
		this->E = 0;
		for (int i = 0; i < V; i++)
		{
			vector<int> *p = new vector<int>;
			adj.push_back(p);
		}
		cinEdge();
	}


	int Vget(){ return V; }
	int Eget(){ return E; }
	vector<int> *getAdj(int i) { return adj[i]; }
	void addEdge(int v,int w)
	{
		adj[v]->push_back(w);
		adj[w]->push_back(v);
		E++;
	}
	void print()
	{
		cout << V << " vertices, " << E << " edges" << endl;
		vector<int>::iterator it;
		for (int i = 0; i < V; i++)
		{
			cout << "[V" << i<<"]";
			for (it = adj[i]->begin(); it != adj[i]->end(); it++)
			{
				cout << "-->" << *it;
			}
			cout << endl;
		}

	}
	~Graph()
	{
		for (int i = 0; i < V; i++)
		{
			delete(adj[i]);
			adj[i] = NULL;
		}

	}


};

int degree(Graph &G, int v)
{
	return G.getAdj(v)->size();
}
int maxDegree(Graph &G)
{
	int m = 0;
	for (int i = 0; i < G.Vget(); i++)
	{
		if (degree(G, i)>m)
			m = degree(G, i);
	}
	return m;
}
int avgDegree(Graph &G)
{
	return 2*G.Eget()/G.Vget();
}
int numOfSelfLoops(Graph &G)
{
	int m = 0;
	for (int i = 0; i < G.Vget(); i++)
	{
		for (int k = 0; k < G.getAdj(i)->size(); k++)
		{
			if (G.getAdj(i)->at(k)==i)
				m++;
		}
	}
	return m / 2;
}