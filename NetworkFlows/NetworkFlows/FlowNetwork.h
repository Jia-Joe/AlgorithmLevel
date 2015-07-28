#pragma once 
#include "stdafx.h"
#include "FlowEdge.h"

class FlowNetwork
{
private:
	int V;//起点0，终点V-1
	int E;
	vector<list<FlowEdge> >  adj;
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

	//v的流量增加delta
	void addResidualFlowTo(FlowEdge &e,int ver, double delta)
	{
		int v = e.from(),w = e.to();
		list<FlowEdge>::iterator it;
		for (it = adj[v].begin(); it != adj[v].end();it++)
		{
			if (it->to() == w)
			{
				if (ver == e.from())
				{
					it->flowReduce(delta);
					e.flowReduce(delta);
				}
				else if (ver == e.to())
				{
					it->flowAdd(delta);
					e.flowAdd(delta);
				}
				else
				{
					runtime_error err("Inconsistent Edge");
					throw err;
				}
				return;
			}
		}
		//if (ver == e.from())
		//	e.flowReduce(delta);
		//else if (ver == e.to())
		//	e.flowAdd(delta);

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
	vector<FlowEdge> allEdge()
	{
		vector<FlowEdge> alledge;
		for (int v = 0; v < V; v++)
		{
			for (FlowEdge e : adjGet(v))
			{
				alledge.push_back(e);
			}
		}
		return alledge;
	}
	void print()
	{
		cout << V << " vertices, " << E << " edges" << endl;
		for (int i = 0; i < V; i++)
		{
			cout << "<V" << i << ">";
			for (FlowEdge e : adj[i])
			{
				int w = e.other(i);
				cout << "-->" << w << '[' <<e.flowGet()<<"-"<< e.capacityGet() << ']';
			}
			cout << endl;
		}
	}
};