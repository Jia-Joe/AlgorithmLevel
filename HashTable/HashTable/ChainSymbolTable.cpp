#include "stdafx.h"
#include "ChainSymbolTable.h"

int _tmain(int argc, _TCHAR* argv[])
{
	class ChainSymbolTable<char, int> *list1;
	list1=new ChainSymbolTable<char, int>('A', 1);
	list1->put('B', 2);
	list1->put('C', 3);
	list1->put('D', 4);
	list1->printList();


	//if (list1->first->next==NULL)
	//	cout << "��" << endl;
	//else
	//	cout << "�ǿ�"<<endl;
	list1->~ChainSymbolTable();
	system("pause");
	return 0;

}