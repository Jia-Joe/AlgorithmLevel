#pragma once
#include "stdafx.h"

class Edge
{
private:
	int v;
	int w;
	double weight;
public:
	Edge(int v, int w, double weight)
	{
		this->v = v;
		this->w = w;
		this->weight = weight;
	}
	bool operator < (const Edge &a) const
	{
		return a.weightGet() < this->weight;
	}
	double weightGet() const
	{
		return weight;
	}
	int from()
	{
		return v;
	}
	int to()
	{
		return w;
	}
	void printEdge()
	{
		cout << v << "-->" << w << " , " << weight << endl;
	}
};

template <class T>
struct Compare
{
	int operator()(const T& x, const T& k) const{
		if (x.weightGet() >= k.weightGet()) return 0;
		else return 1;
	}
};

class EdgeWeightedDigraph_UseSet
{
private:
	int V;
	int E;
	vector<set<Edge, Compare<Edge> > >adj;
public:
	EdgeWeightedDigraph_UseSet(int V)
	{
		this->V = V;
		cin >> this->E;
		for (int i = 0; i < V; i++)
		{
			set<Edge, Compare<Edge> > tmp;
			adj.push_back(tmp);
		}
		int vin, win;
		double weightin;
		for (int k = 0; k < E; k++)
		{
			cin >> vin >> win >> weightin;
			Edge e(vin, win, weightin);
			adj[vin].insert(e);
		}
	}
	int Vget(){ return V; }
	int Eget(){ return E; }
	set<Edge, Compare<Edge> > adjGet(int i) { return adj[i]; }
	void print()
	{
		cout << V << " vertices, " << E << " edges" << endl;
		for (int i = 0; i < V; i++)
		{
			cout << "[V" << i << "]";
			for (Edge e : adj[i])
			{
				int w = e.to();
				cout << "--[" << e.weightGet() << "]-->" << w << " , ";
			}
			cout << endl;
		}
	}
};
class EdgeWeightedDigraph
{
private:
	int V;
	int E;
	vector<list<Edge> >adj;
public:
	EdgeWeightedDigraph(int V)
	{
		this->V = V;
		cin >> this->E;
		for (int i = 0; i < V; i++)
		{
			list<Edge> tmp;
			adj.push_back(tmp);
		}
		int vin, win;
		double weightin;
		for (int k = 0; k < E; k++)
		{
			cin >> vin >> win >> weightin;
			Edge e(vin, win, weightin);
			adj[vin].push_back(e);
		}
	}
	int Vget(){ return V; }
	int Eget(){ return E; }
	list<Edge> adjGet(int i) { return adj[i]; }
	void print()
	{
		cout << V << " vertices, " << E << " edges" << endl;
		for (int i = 0; i < V; i++)
		{
			cout << "<V" << i << ">";
			for (Edge e : adj[i])
			{
				int w = e.to();
				cout << "--" << w << '[' << e.weightGet() << ']';
			}
			cout << endl;
		}
	}
};