#pragma once
#include "stdafx.h"


class Edge
{
private:
	int v;
	int w;
	double weight;
//	Edge *nextEdge;
public:
	Edge(){};
	Edge(int vv, int ww, double wweight) :v(vv), w(ww), weight(wweight)
	{
	//	nextEdge = nullptr;
	};


	//bool operator < (const Edge &a,const Edge &b) const
	//{//隐含this参数，所以参数过多，无法通过编译
	//	return a.weightGet() < b.weightGet();
	//}
	//bool operator < (const Edge &a) const
	//{
	//	return a.weightGet() < this->weight;
	//}
	double weightGet() const
	{
		return weight;
	}
	int either() const
	{
		return v;
	}
	int other(int x)
	{
		if (x == v)
			return w;
		else if (x == w)
			return v;
		else
			//throw new RuntimeException("Not Belong to This Edge");
			return -1;
	}

	void printEdge()
	{
		cout << v << "--" << w << " , " << weight << endl;
	}
};


class EdgeWeightedGraph
{
private:
	int V;
	int E;
	vector<list<Edge*> >adj;
public:
	EdgeWeightedGraph(int V)
	{
		this->V = V;
		cin >> this->E;
		for (int i = 0; i < V; i++)
		{
			//list<Edge*> *tmp = new list<Edge*>;
			list<Edge*> tmp;
			adj.push_back(tmp);
		}
	}
	void input()
	{
		int vin, win;
		double weightin;
		for (int k = 0; k < E; k++)
		{
			cin >> vin >> win >> weightin;
			Edge* e = new Edge(vin, win, weightin);
			if (vin != win)
			{
				adj[vin].push_back(e);
				Edge* e1 = new Edge(vin, win, weightin);
				adj[win].push_back(e1);
			}
			else
				adj[vin].push_back(e);
		}
		//for (int i = 0; i < V; i++)
		//{
		//	Edge* Enull = new Edge();
		//	Enull = nullptr;
		//	adj[i].push_back(Enull);
		//}
	}
	int Vget(){ return V; }
	int Eget(){ return E; }
	list<Edge*> adjGet(int i) { return adj[i]; }
	void print()
	{
		cout << V << " vertices, " << E << " edges" << endl;
		for (int i = 0; i < V; i++)
		{
			cout << "<V" << i << ">";
			for (Edge* e : adj[i])
			{
				int w = e->other(i);
				cout << "--" << w << '[' << e->weightGet() << ']';
			}
			cout << endl;
		}
	}
	~EdgeWeightedGraph()
	{
		for (int i = 0; i < V; i++)
		{
			list<Edge*>::iterator it;
			for (it = adj[i].begin(); it != adj[i].end(); it++)
			{
				//adj[i].remove(*it);
				delete *it;
				*it = 0;
			}
			//delete adj[i];
		}


	}
};