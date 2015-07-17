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
		if (v != w)
		{
			adj[v]->push_back(w);
			adj[w]->push_back(v);
		}
		else
		{
			adj[v]->push_back(v);
		}
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

//头文件中只声明，函数实现应该放在源文件中，否则要加static
//重定义error因为#include是预处理部分，在编译之前由预处理程序在这个部分复制头文件的内容过来
//所以在编译时候，两文件都有函数的定义。那么链接程序就不知道链接那个定义好了（二义性）
static int degree(Graph &G, int v)
{
	return G.getAdj(v)->size();
}
static int maxDegree(Graph &G)
{
	int m = 0;
	for (int i = 0; i < G.Vget(); i++)
	{
		if (degree(G, i)>m)
			m = degree(G, i);
	}
	return m;
}
static int avgDegree(Graph &G)
{
	return 2*G.Eget()/G.Vget();
}
static int numOfSelfLoops(Graph &G)
{
	int m = 0;
	for (int i = 0; i < G.Vget(); i++)
	{
		for (int k = 0; k < G.getAdj(i)->size(); k++)
		{
			if (G.getAdj(i)->at(k)==i)// <=>if ((*(G.getAdj(i)))[k]==i)
				m++;
		}
	}
	return m / 2;
}