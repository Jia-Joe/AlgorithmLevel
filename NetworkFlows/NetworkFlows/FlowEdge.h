#pragma once 
#include "stdafx.h"

class FlowEdge
{
private:
	int v;//边的起点
	int w;//边的终点
	double capacity;
	double flow;
public:
	FlowEdge(int v, int w, double capacity)
	{
		this->v = v;
		this->w = w;
		this->capacity = capacity;
		this->flow = 0.0;
	}
	int from(){ return v; }
	int to() { return w; }
	double capacityGet(){ return capacity; }
	double flowGet(){ return flow; }
	int other(int ver)//vertex
	{
		if (ver == v)return w;
		else if (ver == w)return v;
		else return NULL;
	}
	//v的剩余容量：
	double residualCapacityTo(int ver)
	{
			if (ver == v)return flow;
			else if (ver == w) return capacity - flow; 
			else
			{
				runtime_error err("Inconsistent Edge");
				throw err;
			}
		//throw new RuntimeException("Inconsistent Edge");
	}
	//v的流量增加delta
	void addResidualFlowTo(int ver, double delta)
	{
		if (ver == v) flow -= delta;
		else if (ver == w) flow += delta;
		else
		{
			runtime_error err("Inconsistent Edge");
			throw err;
		}
	}
	void printFlowEdge()
	{
		printf_s("%d-->%d %.2lf %.2lf\n", v, w, capacity, flow);
	}
};