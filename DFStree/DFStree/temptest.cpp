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


int _tmain1(int argc, _TCHAR* argv[])
{

	vector<int> dest = { 3, 4, 99, 6, 7, 8, 9 };

	Nth nth(3);
	//  find_if (beg, end, unaryPred) ;  
	//  ����ǰ:[beg,end)��ʾ��������.unaryPred��������һԪ��������.  
	//  ������:ȷ�������������Ƿ����ʹunaryPred����true��Ԫ��.  
	//  ����ֵ:�������ʹunaryPred����true��Ԫ��,����ָ���һ����Ԫ��λ�õĵ�����.  
	//                  ���򷵻�end.  
	//  ��ע:     ���ʹ�ö�Ԫ��������,��ʹ�ð�������ת��ΪһԪ��������ʹ��.  
	vector<int>::iterator nthItr = find_if(dest.begin(), dest.end(), nth);  //dest����Ϊ�������֣�3,4,5,6,����,12  
	cout << "3rd:" << *nthItr << endl;
	cout << "State:" << nth.GetCount() << endl; 
	int *p = new int;
	system("pause");
	_CrtDumpMemoryLeaks();
	return 0;

}