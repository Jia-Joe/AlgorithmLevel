#include "stdafx.h"

#define NPQ 5

int _tmain(int argc, _TCHAR* argv[])
{
	IndexMinPQ<double> ipq(NPQ);
	ipq.insert(3, 0.4);
	ipq.insert(0, 0.5);
	ipq.insert(2, 0.1);
	ipq.insert(1, 0.8);
	for (int i = 0; i < NPQ; i++)
	{
		cout << ipq.minKey() << "--";
		ipq.delMin();
	}
	cout << endl;
	system("pause");
	return 0;
}
