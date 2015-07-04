#include "stdafx.h"
#include "ChainSymbolTable.h"

int _tmain0(int argc, _TCHAR* argv[])
{
	ChainSymbolTable<string, int> *list1 = new ChainSymbolTable<string, int>;
	list1->put("ABCD", 2);
	list1->put("EF", 3);
	list1->put("GHIJ", 4);
	list1->printList();

	//if (list1->first->next==NULL)
	//	cout << "¿Õ" << endl;
	//else
	//	cout << "·Ç¿Õ"<<endl;
	list1->~ChainSymbolTable();
	system("pause");
	return 0;

}