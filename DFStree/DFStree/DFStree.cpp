// DFStree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Graph.h"

/*#define _CRTDBG_MAP_ALLOC   
#include <crtdbg.h>  
#ifdef _DEBUG  
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)   
#endif  
#include<stdio.h>   
#include<stdlib.h> */ 


//#define VER 2
////bool marked[VER] = { false };
//
////void dfs(EdgeWeightedGraph &G, int v)
////{
////	marked[v] = true;
////	cout << v << " ";
////	for (Edge* e : G.adjGet(v))
////	{
////		if (e != nullptr)
////		{
////			int w = e->other(v);
////			if (!marked[w])
////			{
////				dfs(G, w);
////			}
////		}
////	}
////}
//
//
//int _tmain0(int argc, _TCHAR* argv[])
//{
//	_CrtDumpMemoryLeaks();
//	//_CrtSetBreakAlloc(211);
//	//_CrtSetBreakAlloc(212);
//	//_CrtSetBreakAlloc(213);
//	//_CrtSetBreakAlloc(252);
//	//_CrtSetBreakAlloc(253);
//	//_CrtSetBreakAlloc(256);
//	//_CrtSetBreakAlloc(259);
//	//_CrtSetBreakAlloc(260);
//	//_CrtSetBreakAlloc(267);
//	//_CrtSetBreakAlloc(269);
//	//_CrtSetBreakAlloc(271);
//	//泄漏检测放在析构函数末尾
////	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	//EdgeWeightedGraph *G = new EdgeWeightedGraph(VER);
//
//	//EdgeWeightedGraph G(VER);
////	G.input();
//
////	dfs(G, 0);
//
//	//G->~EdgeWeightedGraph();
//	system("pause");
//	return 0;
//}
//int parent = 0,child;
//Edge e1 = G.adjGet(0).begin;
//bool marked[VER] = { false };

//stack<int> vst;
//stack<Edge> est;
//vst.push(parent);
//est.push(e1);

//while (!vst.empty())
//{

//	while ()
//	{

//	}
//}
