#pragma once
#include<string>

using namespace std;

class rbNode
{
public:
	string key;
	double val;
	rbNode *left, *right;
	int N;//���еĽڵ�����
	bool color;

	rbNode(string key, double val, int N, bool color);
	virtual ~rbNode(){};

};
bool isRed(rbNode *x);


