#pragma once


using namespace std;
class ChainingHashST
{
private :
	int N;//键值对总数
	int M;//散列表大小
	vector<ChainSymbolTable<string, int>*> HashTable;
	unsigned int hash(string s) 
	{
		unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
		unsigned int hash = 0;

		for (int i = 0; i < s.size(); i++)
		{
			hash = hash * seed + unsigned int(s[i]);
		}
		
		return (hash&0x7FFFFFFF)%M;
	}
public:
	ChainingHashST(int M)
	{
		this->M = M;
		vector<ChainSymbolTable<string, int> >::iterator itclass;
		for (int i = 0; i < M; i++)
		{
			ChainSymbolTable<string, int> *list1 = new ChainSymbolTable<string, int>;
			HashTable.push_back(list1);
		}
	}
	ChainingHashST()
	{
		ChainingHashST(17);
	}
	int get(string key)
	{
		return (int)HashTable[hash(key)]->get(key);
	}
	void put(string key, int val)
	{
		unsigned int hk = hash(key);
		HashTable[hash(key)]->put(key, val);
	}
	void printHashTable()
	{
		for (int i = 0; i < M; i++)
			HashTable[i]->printList();
		cout << endl;
	}
	~ChainingHashST()
	{
		for (int i = 0; i < M; i++)
			HashTable[i]->~ChainSymbolTable();
		cout << "~ChainingHashST()" << endl;
	}
};

