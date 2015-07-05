#pragma once

template<class T1=char,class T2=int>
class ChainSymbolTable
{
private:
	class Node
	{
	public:
		T1 key;
		T2 val;
		Node *next;

		Node(){ this->next = NULL; }
		Node(T1 key,T2 val)
		{
			this->key = key;
			this->val = val;
			this->next = NULL;
		}
	};

public:
	Node *first;
	ChainSymbolTable()
	{
		first = new Node;
		first = NULL;
	}
	ChainSymbolTable(T1 key, T2 val)
	{
		first = new Node(key,val);

	}
	T2 get(T1 key)
	{
		for (Node *x = first; x != NULL; x = x->next)
		{
			if (key == x->key)
			{
				return x->val;
			}
		}
		return NULL;
	}
	void put(T1 key, T2 val)
	{

		for (Node *x = first; x != NULL; x = x->next)
		{
			if (key == x->key)
			{
				x->val = val;
			}
		}
		Node *tmp = new Node(key, val);
		tmp->next = first;
		this->first = tmp;

	}

	void printList()
	{
		for (Node *x = first; x!= NULL; x = x->next)
		{
			cout << "[" << x->key << "," << x->val << "]--> ";
		}
		cout << "NULL" << endl;
	}
	virtual ~ChainSymbolTable()
	{
		Node *p=first;
		while (p != NULL)
		{
			Node *x = p;
			p = p->next;
			delete x;
		}
		delete p;
		//cout << "~ChainSymbolTable()" << endl;
	}
};

