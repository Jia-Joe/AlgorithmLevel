#include "stdafx.h"
#include "MaxFlowFun.h"

bool localEq(FlowNetwork &G, int v)
{
	//检查每个顶点的局部平衡
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
	//确认每条边的流量非负且不大于边的容量
	for (int v = 0; v < G.Vget(); v++)
	{
		for (FlowEdge e:G.adjGet(v))
			if (e.flowGet()<0 || e.flowGet()>e.capacityGet())
				return false;
	}
	//检查每个顶点的局部平衡
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