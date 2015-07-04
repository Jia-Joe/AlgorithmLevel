#include "stdafx.h"
#include "ChainingHashST.h"

#define Le 5
int _tmain(int argc, _TCHAR* argv[])
{
	ChainingHashST *ht = new ChainingHashST(11);
	string ts("We have detected your browser as originating from China\
and / or set in Chinese.Please note that one of the rules \
of Quora is that it is English - only for now.All questions");
			//and answers must be in English, although references to a foreign\
			//language are acceptable if they have appropriate context and would\
			//be understandable by an English speaker.For more details, please see\
			//Need Quora questions be written in English ? Thanks for your attention.\
			//If this does not apply to you, please feel free to ignore this message");
					
	for (int i = 0; i < ts.size() / Le-1 ; i++)
	{
		string tmp = ts.substr(i *Le, Le);
		ht->put(tmp,i);
	}
	ht->printHashTable();
	ht->~ChainingHashST();
	system("pause");
	return 0;
}

