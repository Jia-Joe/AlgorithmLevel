#include "stdafx.h"
class LinearProbingHashTable
{
private:
	int N=0;
	int M = 8;
	vector<string*> keys;
	vector<int> vals;
	unsigned int hash(string s)
	{
		unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
		unsigned int hash = 0;

		for (int i = 0; i < s.size(); i++)
		{
			hash = hash * seed + unsigned int(s[i]);
		}

		return (hash & 0x7FFFFFFF) % M;
	}
	void resize(int cap)
	{
		LinearProbingHashTable *pt=new LinearProbingHashTable(cap);
		for (int i = 0; i < M; i++)
		{
			if (keys[i] != NULL)
				pt->put(*keys[i],vals[i]);
		}
		keys = pt->keys;
		vals = pt->vals;
	}

public:
	LinearProbingHashTable(int M)
	{
		this->M = M;
		for (int i = 0; i < M; i++)
		{
			keys[i] = new string;
			keys[i] = NULL;
			vals.push_back(0);
		}
	}
	void put(string key, int val)
	{
		if (N >= M / 2)
			resize(2 * M);
		int i;
		for (i = hash(key); keys[i] != NULL; i = (i + 1) % M)
		{
			if (keys[i] == &key)
			{
				vals[i] = val;
				break;
			}
			else
			{
				keys[i] = &key;
				vals[i] = val;
			}
		}

	}
	int get(string key)
	{
		for (int i = hash(key); keys[i] != NULL; i = (i + 1) % M)
		{
			if (keys[i] == &key)
				return vals[i];
		}
		return NULL;
	}
	void deletekey(string key)
	{
		int i = hash(key);
		while (*keys[i] == key)
		{
			i = (i + 1) % M;
		}
		keys[i] = NULL;
		vals[i] = NULL;
		i = (i + 1) % M;
		while (key[i] != NULL)
		{
			string ktmp = *keys[i];
			int vtmp = vals[i];
			keys[i] = NULL;
			vals[i] = NULL;
			N--;
			put(ktmp, vtmp);
		}
		N--;
		if (N > 0 && N == M / 8)
			resize(M / 2);
	}
};