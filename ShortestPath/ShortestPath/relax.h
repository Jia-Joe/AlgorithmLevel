#pragma once
#include "stdafx.h"

#include "EdgeWeightedDigraph.h"

//�ߵ��ɳ�
void relax(Edge &e);
//������ɳ�
void relax(EdgeWeightedDigraph &G, int v);
double distToGet(int v);
bool hasPathTo(int v);
vector<Edge> pathTo(int v);



