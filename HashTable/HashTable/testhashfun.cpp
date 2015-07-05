#include "stdafx.h"

#include <hash_map>

#define FOR(i,l,h) for(int i=l;i<h;++i)


//extern "C" unsigned int BKDRHash(char *str);
//extern "C"
//{ 
//#include "hashfun.h" 
//}
#include "hashfun.h" 


//int hash(((day*R+month)%M)*R+year)%M;//除留取余法，看做R进制，M为素数

int _tmain3(int argc, _TCHAR* argv[])
{
	vector<ChainSymbolTable<char, int> > ChainHash;

	cout << BKDRHash("12s") << endl<<SDBMHash("12s") << endl;
	//FOR(i, 0, 12)
	//{
	//	cout << addt(i) << endl;
	//	cout << "sss" << endl;
	//}

	cout  << endl;
	system("pause");
	return 0;
}


