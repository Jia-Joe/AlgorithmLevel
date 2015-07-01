#include <rbTreeBasic.h>
#include <rbNode.h>


rbNode *rotateLeft(rbNode *h)//h--->(x)
{
	rbNode *x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	h->color = RED;
	x->N = h->N;
	h->N = 1 + h->left->N + h->right->N;
	return x;
}

rbNode *rotateRight(rbNode *h)//x--->(h)
{
	rbNode *x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;
	h->color = RED;
	x->N = h->N;
	h->N = 1 + h->left->N + h->right->N;
	return x;
}