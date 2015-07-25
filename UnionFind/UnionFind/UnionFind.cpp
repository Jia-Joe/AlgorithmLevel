// UnionFind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int N;
	cin >> N;
	UFquickunion uf(N);
//	UFquickfind uf(N);
	while (true)
	{
		int p,q;
		cin >> p >> q;
		if (uf.connected(p, q))
			continue;
		uf.unionPQ(p, q);
		if (getchar() == '\n')
			break;
	}
	cout << uf.countGet()<<" comonents"<<endl;
	for (int i = 0; i < N; i++)
	{
		cout << uf.find(i) << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}

