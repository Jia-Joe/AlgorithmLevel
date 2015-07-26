#include "stdafx.h"
#include "MaxFlowFun.h"

bool localEq(FlowNetwork &G, int v)
{
	//���ÿ������ľֲ�ƽ��
	double EPSILON = 1e-11;
	double netflow = 0.0;
	for (FlowEdge e : G.adjGet(v))
	{
		if (v == e.from())
			netflow -= e.flowGet();
		else
			netflow += e.flowGet();
		return
			abs(netflow) < EPSILON;
	}
}
bool isFeasible(FlowNetwork &G)
{
	//ȷ��ÿ���ߵ������Ǹ��Ҳ����ڱߵ�����
	for (int v = 0; v < G.Vget(); v++)
	{
		for (FlowEdge e:G.adjGet(v))
			if (e.flowGet()<0 || e.flowGet()>e.capacityGet())
				return false;
	}
	//���ÿ������ľֲ�ƽ��
	for (int v = 0; v < G.Vget(); v++)
	{
		if (v != 0 && v != G.Vget()-1 && !localEq(G,v))
			return false;
	}
	return true;
}

bool hasAugmentingPath(FlowNetwork &G, int s, int v)
{
	return true;
}