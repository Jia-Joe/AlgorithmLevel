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
һ.�ú������
---��2-�ڵ��в����¼�:���---���䣬�Ҳ�---����
---��3-�ڵ��в����¼�:
1.�¼�����������������Ȼ��������ȫ��Ϊ��ɫ
2.�¼���С������,��ɵ�һ�������������������Ȼ��������ȫ��Ϊ��ɫ
3.�¼����У�����,��ɵڶ������������,��ɵ�һ���������������������������ȫ��Ϊ��ɫ

��.��ɫת��
��������ȫ��Ϊ��ɫ֮�󣬽����ڵ��ɺڱ�죬�������ϴ���
�����ڵ㱻��Ϊ��ɫ�������ǿ�Ʊ�Ϊ��ɫ�������Ա��ֺ�������ʣ�����ʹ������ĺڸ߶�+1
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

	//����������if����Ǻ�����еĲ��뺯����BST�еĲ�֮ͬ��
	if (isRed(h->right) && !isRed(h->left))
		h = rotateLeft(h);
	if (isRed(h->left) && (h->left->left!=NULL) && isRed(h->left->left))
		h = rotateRight(h);
	if (isRed(h->right) && isRed(h->left))
		flipColors(h);

	h->N = 1 + size(h->left) + size(h->right);
	return h;
}
//����key�ɹ����������ֵ�������½�һ���ڵ�
void rbTree::put(double key, string val)
{
	root = put(root, key, val);
	root->color = BLACK;
}