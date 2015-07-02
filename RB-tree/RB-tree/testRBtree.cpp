#include <rbTreeBasic.h>
#include <map>

void TraverseTree(rbNode *rn)
{
	if (rn != NULL)
	{
		
		TraverseTree(rn->left);
		cout << rn->val << "  ";
		TraverseTree(rn->right);

	}
}
int main(void)
{
	string ss = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	map<string,int> abc;
	string::iterator  it;
	//map<string,int>::iterator mpit;
	int itcnt = 0;
	for (it = ss.begin(); it!=ss.end(); it++)
	{		
		char tmpchar[1] = { ss[itcnt] };
		string tmpstr;
		tmpstr += tmpchar[0];
		abc[tmpstr]=itcnt;
		itcnt++;		
	}
	itcnt = 0;
	string val[10];
	//测试序列
	string inputval = { "SEARCHXMPL" };
	for (it = inputval.begin(); it != inputval.end(); it++)
	{
		char tmpchar[1] = { inputval[itcnt] };
		string tmpstr;
		tmpstr += tmpchar[0];
		val[itcnt] = tmpstr;
		itcnt++;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << val[i] << "--->" << abc[val[i]]<<endl;
	}

	//红黑树节点插入
	rbTree *rbtree=new rbTree();
	for (int i = 0; i < 10; i++)
	{
		rbtree->put(abc[val[i]], val[i]);
	}
	TraverseTree(rbtree->getroot());
	rbtree->~rbTree();
	//int d = log((double)15) / log(2.0) + 1;
	//vector<string> s;
	//int tot = 15;//totӦȡ3,7,15,31,63,127...
	//for (int i = 0; i < tot; i++)
	//{
	//	char tmp[1] = { 'A' + i - 1 };
	//	string str;
	//	str += tmp[0];
	//	s.push_back(str);
	//}

	//s = { "1", "2", "3", "4", "5", "_", "7", "_", "9", "0", "1", "_", "_", "4", "_" };
	//cout << endl << endl;
	//printRBtree(s, tot);
	//cout << endl << endl;
	//rbNode *h;

	system("pause");
	return 1;
}