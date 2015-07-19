// Digraph.cpp : 定义控制台应用程序的入口点。
//

#pragma once
#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Digraph g(6);
	g.print();

	DirectDFS dfs(g,0);
	for (int i = 0; i < 6; i++)
		cout << "--" << dfs.markedv(i);

	//cout << endl << dfs.Count() << endl << endl;

	//test path
	//DepthFirstPaths dfp(g, 0);
	//for (int i = 0; i < 6; i++)
	//{
	//	
	//	if (dfp.hasPathTo(i))
	//	{
	//		vector<int> tmp = dfp.pathTo(i);
	//		int len = tmp.size()-1;
	//		for (int j = 0; j <=len; j++)
	//		{
	//			if (j == 0)
	//				cout << tmp[len-j];
	//			else
	//				cout << '-' << tmp[len-j];
	//		}
	//		cout << endl;
	//	}
	//}
	//BreadthFirstPaths bfp(g, 0);
	//for (int i = 0; i < 6; i++)
	//{

	//	if (bfp.hasPathTo(i))
	//	{
	//		vector<int> tmp = bfp.pathTo(i);
	//		int len = tmp.size() - 1;
	//		for (int j = 0; j <= len; j++)
	//		{
	//			if (j == 0)
	//				cout << tmp[len - j];
	//			else
	//				cout << '-' << tmp[len - j];
	//		}
	//		cout << endl;
	//	}
	//}
	system("pause");
	return 0;
}

