#pragma once
#include "stdafx.h"

//Edge with next node
class Edge
{
private:
	int v;
	int w;
	double weight;
	Edge *nextEdge = nullptr;
public:
	Edge(){};
	Edge(int vv, int ww, double wweight) :v(vv), w(ww), weight(wweight)
	{
		nextEdge = nullptr;
	};
	Edge* NextEdge()
	{
		return this->nextEdge;
	}
	void setNextEdge(Edge* e)
	{
		this->nextEdge=e;
	}
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
	void printEdge()
	{
		cout << v << "--" << w << " , " << weight << endl;
	}
};


class nGraph
{
private:
	int V;
	int E;
	vector<Edge*> adj;
public:
	nGraph(int V)
	{
		this->V = V;
		cin >> this->E;
		for (int i = 0; i < V; i++)
		{
			adj.push_back(new Edge(-1,-1,0.0));//Head Node
		}
	}
	void input()
	{
		int vin, win;
		double weightin;
		vector<Edge*> gtmp=adj;
		for (int k = 0; k < E; k++)
		{
			cin >> vin >> win >> weightin;
			Edge* e = new Edge(vin, win, weightin);
			if (vin != win)
			{
				gtmp[vin]->setNextEdge(e);
				gtmp[vin] = gtmp[vin]->NextEdge();
				Edge* e1 = new Edge(win, vin, weightin);
				gtmp[win]->setNextEdge(e1);
				gtmp[win] = gtmp[win]->NextEdge();
			}
			else
			{
				gtmp[vin]->setNextEdge(e);
				gtmp[vin] = gtmp[vin]->NextEdge();
			}
		}
	}
	int Vget(){ return V; }
	int Eget(){ return E; }
	Edge* adjGet(int i) { return adj[i]; }
	void print() const
	{
		cout << V << " vertices, " << E << " edges" << endl;
		for (int i = 0; i < V; i++)
		{
			cout << "<V" << i << ">";
			for (Edge* e = adj[i]->NextEdge(); e != nullptr;e=e->NextEdge())
			{
				int w = e->other(i);
				cout << "--" << w << '[' << e->weightGet() << ']';
			}
			cout << endl;
		}
	}
	~nGraph()
	{
		cout << V << endl;
		for (int i = 0; i < V; i++)
		{
			Edge* head = adj[i];
			while (head != nullptr)
			{
				Edge* tmp = head;
				head = head->NextEdge();
				delete tmp;
			}
		}
	}
};

