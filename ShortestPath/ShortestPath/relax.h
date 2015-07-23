#pragma once
#include "stdafx.h"


//╠ъ╣дкиЁз
void relax(Edge &e);
//╤╔╣Ц╣дкиЁз
void relax(EdgeWeightedDigraph &G, int v);
double distToGet(int v);
bool hasPathTo(int v);
vector<Edge> pathTo(int v);



