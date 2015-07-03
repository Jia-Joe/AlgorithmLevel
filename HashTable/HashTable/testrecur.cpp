#include "stdafx.h"

int addt(int n)
{
	if (n == 5)
	{
		cout << 5 << endl;
		return 5;
	}
	else
	{

		int x = addt(n + 1) - 1;
		cout << x << endl;
		return x;
	}
}