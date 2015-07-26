#pragma once 
#include "stdafx.h"
#include "FlowEdge.h"

class FlowNetwork
{
private:
	int V;//起点0，终点V-1
	int E;
	vector<list<FlowEdge> >adj;
public:
	FlowNetwork(){}
	FlowNetwork(int V)
	{
		this->V = V;
		this->E = 0;
		for (int i = 0; i < V; i++)
		{
			list<FlowEdge> tmp;
			adj.push_back(tmp);
		}
	}
	void addEdge(FlowEdge e)
	{
		//不同于无向图
		adj[e.from()].push_back(e);
		adj[e.to()].push_back(e);
		E++;
	}
	int Vget(){ return V; }
	int Eget(){ return E; }
	list<FlowEdge> adjGet(int i) { return adj[i]; }
	void print()
	{
		cout << V << " vertices, " << E << " edges" << endl;
		for (int i = 0; i < V; i++)
		{
			cout << "<V" << i << ">";
			for (FlowEdge e : adj[i])
			{
				int w = e.to();
				cout << "-->" << w << '[' <<e.flowGet()<<"--"<< e.capacityGet() << ']';
			}
			cout << endl;
		}
	}
};