#include <rbTreeBasic.h>

int rbTree::size(rbNode *x)
{
	if (x == NULL)
		return 0;
	else
		return x->N;
}
rbNode *rbTree::rotateLeft(rbNode *h)//h--->(x)
{
	rbNode *x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	h->color = RED;
	x->N = h->N;
	h->N = 1 + size(h->left) + size(h->right);
	return x;
}

rbNode *rbTree::rotateRight(rbNode *h)//x--->(h)
{
	rbNode *x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;
	h->color = RED;
	x->N = h->N;
	h->N = 1 + size(h->left) + size(h->right);
	return x;
}

bool rbTree::isRed(rbNode *x)
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

void rbTree::flipColors(rbNode *h)
{
	h->color = RED;
	h->left->color = BLACK;
	h->right->color = BLACK;
}
/***********************************************************************************
一.用红键插入
---向2-节点中插入新键:左插---不变，右插---左旋
---向3-节点中插入新键:
1.新键最大：则产生两红链，然后将两红链全变为黑色
2.新键最小：右旋,变成第一种情况，产生两红链，然后将两红链全变为黑色
3.新键居中：左旋,变成第二种情况，右旋,变成第一种情况，产生两红链，将两红链全变为黑色

二.颜色转换
将两红链全变为黑色之后，将父节点由黑变红，即可向上传递
若根节点被变为红色，则必须强制变为黑色，这样仍保持红黑树性质，但会使红黑树的黑高度+1
************************************************************************************/

rbNode * rbTree::put(rbNode *h, double key, string val)
{
	if (h == NULL)
	{
		return new rbNode(key, val, 1, RED);
	}
	int cmp = key - (h->key);
	if (cmp < 0)
		h->left = put(h->left, key, val);
	else if (cmp>0)
		h->right = put(h->right, key, val);
	else
		h->val = val;

	//接下来三条if语句是红黑树中的插入函数与BST中的不同之处
	if (isRed(h->right) && !isRed(h->left))
		h = rotateLeft(h);
	if (isRed(h->left) && (h->left->left!=NULL) && isRed(h->left->left))
		h = rotateRight(h);
	if (isRed(h->right) && isRed(h->left))
		flipColors(h);

	h->N = 1 + size(h->left) + size(h->right);
	return h;
}
//查找key成功，则更新其值，否则新建一个节点
void rbTree::put(double key, string val)
{
	root = put(root, key, val);
	root->color = BLACK;
}