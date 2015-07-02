#pragma once


using namespace std;

class rbNode
{
public:
	double key;
	string val;
	rbNode *left, *right;
	int N;//树中的节点总数
	bool color;
	rbNode(){};
	rbNode(double key, string val, int N, bool color);
	virtual ~rbNode(){};

};

class rbTree
{
private:
	rbNode *root;
	int size(rbNode *x);
	bool isRed(rbNode *x);
	rbNode *rotateLeft(rbNode *h);
	rbNode *rotateRight(rbNode *h);
	void flipColors(rbNode *h);
	rbNode *put(rbNode *h, double key, string val);
public:
	rbTree()
	{
		root=new rbNode();
		root = NULL;
	}
	void deleteTree(rbNode *rn);
	~rbTree()
	{ 
		deleteTree(root); 
		cout <<endl<< "Delete RBTree!"<<endl; 
	}
	void put(double key, string val);
	rbNode  *getroot(){ return root; }
	rbNode  *lchild(){ return root->left; }
	rbNode  *rchild(){ return root->right; }
};


