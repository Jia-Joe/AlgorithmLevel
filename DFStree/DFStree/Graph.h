#pragma once
#include "stdafx.h"


class Edge
{
private:
	int v;
	int w;
	double weight;
public:
	Edge(int v, int w, double weight) :v(v), w(w), weight(weight){};
	//{
	//	this->v = v;
	//	this->w = w;
	//	this->weight = weight;
	//}

	//bool operator < (const Edge &a,const Edge &b) const
	//{//隐含this参数，所以参数过多，无法通过编译
	//	return a.weightGet() < b.weightGet();
	//}
	bool operator < (const Edge &a) const
	{
		return a.weightGet() < this->weight;
	}
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
	int compareTo(Edge that)
	{
		if (this->weightGet() < that.weightGet())
			return -1;
		else if (this->weightGet() > that.weightGet())
			return 1;
		else
			return 0;
	}
	void printEdge()
	{
		cout << v << "--" << w << " , " << weight << endl;
	}
};

template <class T>
struct Compare
{
	int operator()(const T& x, const T& k) const{
		if (x.either() >= k.either()) return 0;
		else return 1;
	}
};

class EdgeWeightedGraph_UseSet
{
private:
	int V;
	int E;
	vector<set<Edge, Compare<Edge> > >adj;
public:
	EdgeWeightedGraph_UseSet(int V)
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
			if (vin != win)
			{
				adj[vin].insert(e);
				adj[win].insert(e);
			}
			else
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
				int w = e.other(i);
				cout << "--[" << e.weightGet() << "]--" << w << " , ";
			}
			cout << endl;
		}
	}
};
class EdgeWeightedGraph
{
private:
	int V;
	int E;
	vector<list<Edge> >adj;
public:
	EdgeWeightedGraph(int V)
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
			if (vin != win)
			{
				adj[vin].push_back(e);
				adj[win].push_back(e);
			}
			else
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
				int w = e.other(i);
				cout << "--" << w << '[' << e.weightGet() << ']';
			}
			cout << endl;
		}
	}
};