// DFStree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Graph.h"

#define _CRTDBG_MAP_ALLOC   
#include <crtdbg.h>  
#ifdef _DEBUG  
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)   
#endif  
#include<stdio.h>   
#include<stdlib.h>  


#define VER 16
bool marked[VER] = { false };
int dfs_num[VER] = { 0 };
int dfs_num_cnt = 1;

void dfs(EdgeWeightedGraph &G, int v)
{
	marked[v] = true;
	//TODO:preWORK on v
	dfs_num[v] = dfs_num_cnt;
	dfs_num_cnt++;
	for (Edge* e : G.adjGet(v))
	{
		if (e != nullptr)
		{
			int w = e->other(v);
			if (!marked[w])
			{
				cout << v << "-->" << w << endl;
				dfs(G, w);
				//TODO:postWORK for (v,w)
				cout << "searchEND......."<<v << "-->" << w << endl;
			}
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//退出时检测泄漏
#endif

	//EdgeWeightedGraph G(VER);
	//G.input();

	int aa = 1, bb = 2, cc = 3;
	int *a = &aa, *b = &bb, *c = &cc;
	list<int*> vp = { nullptr,a, b,c, nullptr };
	vp.push_back(nullptr);
	stack<int*> sp;
	for (list<int*>::iterator it = vp.begin(); it != vp.end(); it++)
	{
		sp.push(*it);
	}
	while (!sp.empty())
	{
		//if (sp.top() == nullptr)
		//	cout << -1;
		//else
			cout << sp.top()<<endl;
		sp.pop();
	}
	//dfs(G, 0);
	//for each (int num in dfs_num)
	//{
	//	cout << num << endl;
	//}


	system("pause");
	return 0;
}
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
