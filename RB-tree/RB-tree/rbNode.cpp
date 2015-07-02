#include <rbTreeBasic.h>

rbNode::rbNode(double key, string val, int N, bool color)
{
	this->key = key;
	this->val = val;
	this->N = N;
	this->color = color;
	this->left = NULL;
	this->right = NULL;
}




