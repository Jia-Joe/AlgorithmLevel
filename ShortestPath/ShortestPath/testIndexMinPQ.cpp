#include "stdafx.h"

#define NPQ 8

struct ds
{
	int v;
	double dis;
	bool operator < (const ds &a)const
	{
		return a.dis < dis;//修改规则，成为最小堆
	}
};

int _tmainIMPQ(int argc, _TCHAR* argv[])
{
	map<int, ds> mp;
	for (int i = 0; i < NPQ; i++)
	{
		ds a{ i,i*i*i%9+0.5 };
		mp[i] = a;
	}

	priority_queue<ds> pqm;
	int cnt = 0;
	ds a1 = ds{ 2, 0.3213 };
	pqm.push(a1); cnt++;
	a1 = ds{ 2, 0.3145 };
	pqm.push(a1); cnt++;
	pqm.push(ds{ 7, 0.8 }); cnt++;
	pqm.push(ds{ 2, 0.2 }); cnt++;
	pqm.push(ds{ 7, 0.4 }); cnt++;
	for (int i = 0; i < cnt; i++)
	{
		cout<<pqm.top().dis<<"|-->";
		pqm.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}


int _tmainPQ(int argc, _TCHAR* argv[])
{
	IndexMinPQ<double> ipq;
	ipq.IndexMinPQInit(NPQ);
	ipq.insert(3, 0.4);
	ipq.print();
	ipq.insert(0, 0.5);
	ipq.print();
	ipq.insert(2, 0.1);
	ipq.print();
	ipq.insert(1, 0.8);
	ipq.print();
	ipq.insert(4, 0.08);
	ipq.print();
	ipq.insert(7, 0.35);
//	ipq.deleteK(4);
	ipq.change(4, 0.314);
	ipq.print();
	for (int i = 0; i < NPQ; i++)
	{
		cout << i << "--" << ipq.contains(i) << endl;
	}

	int ipqN = ipq.getN();
	for (int i = 0; i < ipqN; i++)
	{
		cout << ipq.min() << "-->";
		ipq.delMin();
	}
	cout << endl;

	system("pause");
	return 0;
}
/*
Output:
0.4--
0.4--0.5--
0.1--0.5--0.4--
0.1--0.5--0.4--0.8--
0.08--0.1--0.4--0.8--0.5--
0.1--0.314--0.35--0.8--0.5--0.4--
0.1-->0.314-->0.35-->0.4-->0.5-->0.8-->
*/
