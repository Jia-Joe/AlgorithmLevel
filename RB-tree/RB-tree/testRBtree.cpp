#include<rbTreeBasic.h>

//最坏情况下红黑树高度2logN,考虑到print效果，Nt可以取小一些
int Nt = 15;
//节点遍历
void TraverseTree(rbNode *rn)
{
	if (rn != NULL)
	{

		TraverseTree(rn->left);
		cout << rn->val << "  ";
		TraverseTree(rn->right);

	}
}

//将所有节点转化为string数组，以便输出打印
//"_0"代表空节点，"X0"代表节点X为黑色，"X1"代表节点X为红色
void iTraverseTree(rbNode *rn, int x, vector<string> &v)
{
	if (rn != NULL)
	{
		//cout << x << "  ";
		//cout << rn->val << "  "<<endl;
		v[x - 1] = rn->val;
		if (rn->color == RED)
			v[x - 1] += "1";
		else
			v[x - 1] += "0";
		//cout << v[x - 1] << " ";
		iTraverseTree(rn->left, 2 * x, v);
		iTraverseTree(rn->right, 2 * x + 1, v);

	}
}


int main(void)
{
	string ss = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	map<string, int> abc;
	string::iterator  it;
	//map<string,int>::iterator mpit;
	int itcnt = 0;
	for (it = ss.begin(); it != ss.end(); it++)
	{
		char tmpchar[1] = { ss[itcnt] };
		string tmpstr;
		tmpstr += tmpchar[0];
		abc[tmpstr] = itcnt;
		itcnt++;
	}


	//测试序列
	string inputval = { "SEARCHXMPL" };
	//string inputval = { "ACEHLMPRSX" };

	int inputlen = inputval.length();


	//生成key->value
	itcnt = 0;
	string val[31];
	for (it = inputval.begin(); it != inputval.end(); it++)
	{
		char tmpchar[1] = { inputval[itcnt] };
		string tmpstr;
		tmpstr += tmpchar[0];
		val[itcnt] = tmpstr;
		itcnt++;
	}
	//for (int i = 0; i < inputlen; i++)
	//{
	//	cout << val[i] << "--->" << abc[val[i]] << endl;
	//}
	//cout << inputlen << endl;
	//int input2pow = pow(2, int(log(inputlen) / log(2.0)) + 1) - 1;
	//cout << input2pow << endl;


	//红黑树节点插入
	rbTree *rbtree = new rbTree();
	for (int i = 0; i < inputlen; i++)
	{
		vector<string> v;
		for (int i = 0; i < Nt; i++)
		{
			v.push_back("_0");
		}
		cout << "Insert node : " << val[i] << endl;
		rbtree->put(abc[val[i]], val[i]);
		iTraverseTree(rbtree->getroot(), 1, v);
		printRBtree(v, Nt);
		cout << endl;
	}

	//	TraverseTree(rbtree->getroot());
	//iTraverseTree(rbtree->getroot(), 1, v);
	//cout << endl;
	//for (int i = 0; i < Nt; i++)
	//{
	//	cout << v[i]<<" ";
	//}
	//cout << endl << endl;
	//printRBtree(v, Nt);
	cout << endl << endl;
	rbtree->~rbTree();

	system("pause");
	return 1;
}