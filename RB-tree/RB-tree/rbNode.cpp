#include <rbTreeBasic.h>

rbNode::rbNode(string key, double val, int N, bool color)
{
	this->key = key;
	this->val = val;
	this->N = N;
	this->color = color;
}





bool isRed(rbNode *x)
{
	if (x == NULL)
	{
		return false;
	}
	else
	{
		return x->color == true;
	}
}