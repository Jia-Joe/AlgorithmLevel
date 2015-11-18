// DFStree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "nGraph.h"

#define _CRTDBG_MAP_ALLOC   
#include <crtdbg.h>  
#ifdef _DEBUG  
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)   
#endif  
#include<stdio.h>   
#include<stdlib.h>  


#define VER 16
bool mark[VER] = { false };
int dfsnum[VER] = { 0 };
int dfsnum_cnt = 1;

inline int vpop(stack<int> &s)
{
	int x = s.top();
	s.pop();
	return x;
}
inline Edge* epop(stack<Edge*> &s)
{
	Edge* x = s.top();
	s.pop();
	return x;
}

int _tmain(int argc, _TCHAR* argv[])
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�˳�ʱ���й©
#endif

	nGraph G(VER);
	G.input();
	G.print();

	
	Edge* e1 = G.adjGet(0);
	int parent = 0, child = e1->other(0);

	stack<int> vst;
	stack<Edge*> est;

	mark[0] = true;
	vst.push(parent);
	est.push(e1->NextEdge());

	while (!vst.empty())
	{
		Edge* Edetect = epop(est);
		if (Edetect != nullptr)
		{
			Edge* eNext = Edetect->NextEdge();
			est.push(eNext);
		}

		while (Edetect!=nullptr)
		{
			child = Edetect->other(parent);
			if (!mark[child])
			{
				mark[child] = true;
				//TODO: preWORK on child
				cout << parent << "  " << child << endl;
				Edetect = G.adjGet(child)->NextEdge();//�ܿ�����ͷ���-		est	{ size=1 }	std::stack<Edge *,std::deque<Edge *,std::allocator<Edge *> > >
				parent = child;
				child = Edetect->other(parent);
				est.push(Edetect->NextEdge());
				vst.push(parent);
			}
			else
			{
				//TODO: postWORK for (parent,child)
				//cout << parent << "  " << child << endl;
				Edetect = Edetect->NextEdge();//һ�������ѱ�ǽ�㣬��Ѱ��nextEdge
				est.pop();
				if (Edetect!=nullptr)
					est.push(Edetect->NextEdge());
			}

		}
		vst.pop();
		if (!vst.empty())//��ֹ����㴦�ظ�pop
			parent = vst.top();
		//TODO: postWORK for (parent,child)
		//cout << parent << "  " << child << endl;
	}


	system("pause");
	return 0;
}

//nGraph *G=new nGraph(VER);
//G->input();
//G->print();
//G->~nGraph();