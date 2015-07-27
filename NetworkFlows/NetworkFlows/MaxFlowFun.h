#pragma once 
#include "stdafx.h"
#include"FlowNetwork.h"

bool localEq(FlowNetwork &G, int v);
bool isFeasible(FlowNetwork &G);

//bool hasAugmentingPath(FlowNetwork &G, int s, int v);
