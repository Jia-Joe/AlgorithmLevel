#pragma once
#include "stdafx.h"

#include "EdgeWeightedDigraph.h"
#include "FindCycle.h"
//�������s�޷����︺Ȩ����distTo[s]��ʼ��Ϊ0������INF,������˳���������ͼ�����бߣ��ظ�V��
//���ɷ�֤����v0->v1->...->vk,��i�ַ��ɣ��õ�s��vi�����·����k�������V-1

class BellmanFordSP
{
private:
	int s;
	vector<double> distTo;
	vector<Edge> edgeTo;
	vector<bool> onQ;
	queue<int> queue;
	int cost;//relax���ô���
	vector<int> cycle;

	void relax(EdgeWeightedDigraph &G, int v);
	void findNegativeCycle();
public:
	BellmanFordSP(EdgeWeightedDigraph &G, int s);
	bool hasNegtiveCycle();
	vector<int> negtiveCycle();

	double disToV(int v)
	{
		return distTo[v];
	}
	bool hasPathTo(int v)
	{
		return !(distTo[v] == INF);
	}
	void printPathTo(int v);
};