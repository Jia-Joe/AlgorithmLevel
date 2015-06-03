#include <HeapOp.h>

class MaxPQ:public Heap
{
public:
	MaxPQ(vector<int> v)
	{ 
		this->hp=v;
		this->hp.push_back(-1); 
		this->N=hp.size()-1;
	}
	bool isEmpty()
	{ return N==0; }
	int size()
	{ return N; }
//	int delMax(){return 9999;}
};



//int main()
//{
//	vector<int> v;
////	int x[12]={1,2,3,4,5,6,7,8,9,10,11,12};
//	int x[12]={1,20,3,40,5,6,7,8,9,10,11,12};
//
//	MaxPQ mypq(v);
//	for(int i=0;i<12;i++) {
//		mypq.insert(x[i]);
//	}
//	//mypq.insert(10);
//	//cout<<mypq.isEmpty()<<endl;
//	cout<<"N="<<mypq.getN()<<endl;
//	assert(mypq.getN()==12);
//	print2tree(mypq.gethp());
//	//mypq.insert(12);mypq.insert(1);
//	cout<<endl<<endl;
//	print2tree(mypq.gethp());
//	cout<<endl<<endl;
//	cout<<"Max value="<<mypq.delMax()<<endl;
//	print2tree(mypq.gethp());
//	cout<<endl<<endl;
//	for(int i=1;i<12;i++)
//	{
//		cout<<mypq.delMax()<<' ';
//	}
//	cout<<endl;
//	system("pause");
//	return 1;
//}