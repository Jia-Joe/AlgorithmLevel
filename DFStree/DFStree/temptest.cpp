#include "stdafx.h"

//#define _CRTDBG_MAP_ALLOC   
//#include <crtdbg.h>  
//#ifdef _DEBUG  
//#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)   
//#endif  
//#include<stdio.h>   
//#include<stdlib.h>  

class Nth
{
public:
	Nth(int n = 0) :m_nth(n), m_count(1){}
	bool operator() (int)
	{
		return m_count++ == m_nth;
	}

	int GetCount()const
	{
		return m_count;
	}

private:
	int m_nth;
	int m_count;
};

inline int spop(stack<int> &s)
{
	int x = s.top();
	s.pop();
	return x;
}
int _tmain2(int argc, _TCHAR* argv[])
{
	//#ifdef _DEBUG
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//退出时检测泄漏
	//#endif
	stack<int> si;
	si.push(1);
	si.push(2);
	si.push(3);
	while (!si.empty())
		cout << spop(si) << endl;

	vector<int> dest = { 3, 4, 99, 6, 7, 8, 9 };

	Nth nth(3);
	//  find_if (beg, end, unaryPred) ;  
	//  操作前:[beg,end)标示输入序列.unaryPred操作符是一元函数对象.  
	//  操作后:确定输入序列中是否存在使unaryPred返回true的元素.  
	//  返回值:如果存在使unaryPred返回true的元素,返回指向第一个该元素位置的迭代器.  
	//                  否则返回end.  
	//  备注:     如果使用二元函数对象,需使用绑定器将其转换为一元函数对象使用.  
	vector<int>::iterator nthItr = find_if(dest.begin(), dest.end(), nth);  //dest内容为连续数字：3,4,5,6,……,12  
	cout << "3rd:" << *nthItr << endl;
	cout << "State:" << nth.GetCount() << endl; 
	//int *p = new int;
	system("pause");
	//_CrtDumpMemoryLeaks();
	return 0;

}