#pragma once
#include "stdafx.h"

#define NUM 10000000

//Space:E,Time:ElogE
class LazyPrimMST
{
private:
	vector<bool> marked;//�����С�������Ķ���
	vector<Edge> mst;//��С�������ı�
	priority_queue<Edge> pq;//���бߣ�����ʧЧ�ıߣ�
	void visit(EdgeWeightedGraph &G, int v)
	{
		//���v������������v��δ��Ƕ���ı߼���pq
		marked[v]=true;
		for (Edge e : G.adjGet(v))
		{
			if (!marked[e.other(v)])
				pq.push(e);
		}
	}
public:
	LazyPrimMST(EdgeWeightedGraph &G)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
		}
		visit(G, 0);
		while (!pq.empty())
		{
			Edge e = pq.top();
			pq.pop();
			int v = e.either(),w=e.other(v);
			if (marked[v] && marked[w])
				continue;
			mst.push_back(e);
			if (!marked[v])
				visit(G, v);
			else
				visit(G, w);
		}
	}

	vector<Edge> mstGet()
	{
		return mst;
	}
	double weightGet()
	{
		double wsum=0;
		for (Edge e : mst)
		{
			wsum += e.weightGet();
		}
		return wsum;
	}
};

//Space:V,Time:ElogV(IndexMinPQ Based)
class PrimMST
{
private:
	vector<Edge> EdgeTo;
	vector<bool> marked;//��v�����У�marked[v]=true
	vector<double> distTo;//distTo[w]=edgeTo[w].weightget()
	list<int> vindex;
	vector<Edge> mst; 
	void visit(EdgeWeightedGraph &G, int v)
	{
		//���v������������v��δ��Ƕ���ı߼���pq
		marked[v] = true;
		for (Edge e : G.adjGet(v))
		{
			int w = e.other(v);
			if (marked[w])
				continue;
			if (e.weightGet() < distTo[w])
			{
				EdgeTo[w] = e;
				distTo[w] = e.weightGet();
			}
		}
	}
public:
	PrimMST(EdgeWeightedGraph &G)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			Edge newE(0,0,NUM);
			EdgeTo.push_back(newE);
			marked.push_back(false);
			distTo.push_back(NUM);
		}
		visit(G, 0);
		for (int ii = 0; ii < G.Vget()-1; ii++)
		{
			double cmp = NUM;
			int imin = 0;
			//cout << NUM << "-";
			for (int i = 0; i < G.Vget();i++)
			{
				if (!marked[i] && (EdgeTo[i].weightGet() < cmp))
				{
					cmp = EdgeTo[i].weightGet();
					imin = i;
				}
			}
			mst.push_back(EdgeTo[imin]);
			visit(G, imin);
		}
	}

	vector<Edge> mstGet()
	{
		return mst;
	}
	double weightGet()
	{
		double wsum = 0;
		for (Edge e : mst)
		{
			wsum += e.weightGet();
		}
		return wsum;
	}
};