#include "stdafx.h"

class Graph
{
private:
	int V;
	int E;
	vector<vector<int> *> adj;
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
	}

	void cinEdge()
	{
		int Enum;
		cin >> Enum;
		for (int i = 0; i < Enum; i++)
		{
			int v, w;
			cin >> v >> w;
			addEdge(v, w);
		}
	}
	int Vget(){ return V; }
	int Eget(){ return E; }

	void addEdge(int v,int w)
	{
		adj[v]->push_back(w);
		adj[w]->push_back(v);
		E++;
	}
	void print()
	{
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