#pragma once
#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//typedef vector<int> vint;
	//vector<vint> adj;
	Graph g(13);
	g.print();
	CC cc(g);
	int cnt = cc.getcount();
	vector<vector<int>*> group;
	for (int i = 0; i < cnt; i++)
	{
		vector<int> *tmp = new vector<int>;
		group.push_back(tmp);
	}
	for (int i = 0; i < g.Vget(); i++)
	{
		group[cc.getid(i)]->push_back(i);
	}
	for (int i = 0; i < cnt; i++)
	{
		for (int w : *group[i])
		{
			cout << '-' << w;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}