#define NDEBUG 

#include <rbTreeBasic.h>
//#include <rbNobe.h>
#include <vector>
#include <assert.h>

int setwN=3;

void outchar(string a, int n);  //输出不带括号的字符代表黑色节点
void outchar(string a, int n, bool isRchildBefore);
void outchar(char a, int n);
void Routchar(string a, int n, bool isRchildBefore); //在第n个位置输出红色节点
void Routchar(string a, int n, bool isRchildBefore); //输出含有括号的字符代表红色节点

//setwN=1，输出普通二叉树
void print2tree(vector <string> s, int n) 
{
	int dpt = log((double)n) / log(2.0) + 1;
	int mid = pow(2,dpt-1);
	//输出根节点
	for (int i = 1; i<mid; i++)
	{
		cout << setw(setwN)<<' ';
	}
	int cnt = 0;
	cout << setw(setwN)<<s[cnt++] << endl;
	for (int i = dpt-1; i>0; i--)
	{
		int leafmin = pow(2, i-1);//1
		int leafstep = leafmin * 2;//2
		int leafnum = pow(2, dpt - i);//8
		vector<int> leafindex, leafindexbefore;
		//输出第一行
		outchar(':', leafstep);
		for (int ii = 1; ii < leafnum/2; ii++)
		{
			outchar(':', leafstep * 2);
		}
		cout << endl;
		//输出第二行
		for (int j = 0; j < leafnum/2; j++)
		{
			outchar('.', leafmin);
			for (int k = 0; k < setwN*leafstep; k++)
			{
				if (k == setwN*leafstep - 1)
					cout << '.';
				else
					cout << ':';
			}
			for (int k = 0; k < leafstep/2; k++)
			{
				cout << setw(setwN) << ' ';
			}
		}
		cout << endl;
		//输出第三行
		outchar(':', leafmin);
		for (int ii = 1; ii < leafnum; ii++)
		{
			outchar(':', leafstep);
		}
		cout << endl;
		//输出第四行
		outchar(s[cnt++], leafmin);
		for (int ii = 1; ii < leafnum; ii++)
		{
			outchar(s[cnt++], leafstep);
		}
		cout << endl;
	}
	
}
//setwN>2，输出满的红黑树
void printFullRBtree(vector <string> s, int n)
{
	int dpt = log((double)n) / log(2.0) + 1;
	int mid = pow(2, dpt - 1);
	//输出根节点,根节点一定是黑色的
	int cnt = 0;
	outchar(s[cnt++], mid, false);
	bool isRchild = false;

	cout << endl;
	for (int i = dpt - 1; i>0; i--)
	{
		int leafmin = pow(2, i - 1);//1
		int leafstep = leafmin * 2;//2
		int leafnum = pow(2, dpt - i);//8
		vector<int> leafindex, leafindexbefore;
		////输出第一行
		outchar(':', leafstep);
		for (int ii = 1; ii < leafnum / 2; ii++)
		{
			outchar(':', leafstep * 2);
		}
		cout << endl;
		//输出第二行
		for (int j = 0; j < leafnum / 2; j++)
		{
			outchar('.', leafmin);
			for (int k = 0; k < setwN*leafstep; k++)
			{
				if (k == setwN*leafstep - 1)
					cout << '.';
				else
					cout << ':';
			}
			for (int k = 0; k < leafstep / 2; k++)
			{
				cout << setw(setwN) << ' ';
			}
		}
		cout << endl;
		//输出第三行
		outchar(':', leafmin);
		for (int ii = 1; ii < leafnum; ii++)
		{
			outchar(':', leafstep);
		}
		cout << endl;
		//输出第四行
		if (cnt % 3== 0)
		{
			Routchar(s[cnt++], leafmin, false);//行首节点可以无视isChildBefore
			isRchild = true;
		}
		else
		{
			outchar(s[cnt++], leafmin, false);
			isRchild = false;
		}
		for (int ii = 1; ii < leafnum; ii++)
		{

			if (cnt % 3 == 0)
			{

				Routchar(s[cnt++], leafstep, isRchild);
				isRchild = true;
			}				
			else
			{
				outchar(s[cnt++], leafstep, isRchild);
				isRchild = false;
			}
		}
		cout << endl;
	}

}

//setwN>2，输出一般红黑树
void printRBtree(vector <string> s, int n)
{
	int dpt = log((double)n) / log(2.0) + 1;
	int mid = pow(2, dpt - 1);
	//输出根节点,根节点一定是黑色的
	int cnt = 0;
	outchar(s[cnt++], mid, false);
	bool isRchild = false;

	cout << endl;
	for (int i = dpt - 1; i>0; i--)
	{
		int leafmin = pow(2, i - 1);//1
		int leafstep = leafmin * 2;//2
		int leafnum = pow(2, dpt - i);//8
		vector<int> leafindex, leafindexbefore;

		//输出第一行
		if (s[(cnt + 1) / 2 - 1] == "_")
			outchar(' ', leafstep);
		else
			outchar(':', leafstep);
		for (int ii = 1; ii < leafnum / 2; ii++)
		{
			if (s[(cnt + 1) / 2 - 1+ii] == "_")
				outchar(' ', leafstep * 2);
			else
				outchar(':', leafstep * 2);
		}
		cout << endl;

		//输出第二行
		for (int j = 0; j < leafnum / 2; j++)
		{
			//输出左半部分
			if (s[cnt + 2 * j] == "_")
			{
				outchar(' ', leafmin);
				for (int k = 0; k < setwN*leafstep / 2 - 1; k++)
				{
						cout << ' ';
				}
			}
			else
			{
				outchar('.', leafmin);
				for (int k = 0; k < setwN*leafstep / 2 - 1; k++)
				{
					cout << ':';
				}
			}
			//输出中间部分
			if (s[(cnt + 1) / 2 - 1+j] == "_")
				cout << ' ';
			else
				cout << ':';
			//输出右半部分
			if (s[cnt + 2 * j+1] == "_")
			{				
				for (int k = 0; k < setwN*leafstep / 2 - 1; k++)
				{
					cout << ' ';
				}
				cout << ' ';
			}
			else
			{
				for (int k = 0; k < setwN*leafstep / 2 - 1; k++)
				{
					cout << ':';
				}
				cout << '.';
			}

			for (int k = 0; k < leafstep / 2; k++)
			{
				cout << setw(setwN) << ' ';
			}
		}
		cout << endl;

		//输出第三行
		if (s[cnt] == "_")
			outchar(' ', leafmin);
		else
			outchar(':', leafmin);
		for (int ii = 1; ii < leafnum; ii++)
		{
			if (s[cnt+ii]=="_")
				outchar(' ', leafstep);
			else
				outchar(':', leafstep);
		}
		cout << endl;

		//输出第四行:节点关键字
		if (cnt % 3 == 0)
		{
			Routchar(s[cnt++], leafmin, false);//行首节点可以无视isChildBefore
			isRchild = true;
		}
		else
		{
			outchar(s[cnt++], leafmin, false);
			isRchild = false;
		}
		for (int ii = 1; ii < leafnum; ii++)
		{

			if (cnt % 3 == 0)
			{

				Routchar(s[cnt++], leafstep, isRchild);
				isRchild = true;
			}
			else
			{
				outchar(s[cnt++], leafstep, isRchild);
				isRchild = false;
			}
		}
		cout << endl;
	}

}
void recurPrint(int mid,int n)
{
	if(n != 0)
	{
		int midleft = mid;
		int midright = mid;
		int dp = pow(2, n - 1);
		for (int i = 0; i < dp; i++)
		{
			midleft--;
			midright++;
			outchar('/', midleft);
			outchar('\\', midright - midleft);
			cout << endl;
		}

		outchar('A', midleft);
		outchar('B', midright - midleft);
		cout << endl;
		recurPrint(midleft, n - 1);
		recurPrint(midright, n - 1);
	}
}

void outchar(char a, int n)
{
	for (int i = 1; i<n; i++)
	{
		cout << setw(setwN) << ' ';
	}
	cout << setw(setwN)<<a;
}

void outchar(string a, int n, bool isRchildBefore)
{
	if (a == "_")
	{
		for (int i = 1; i<n; i++)
		{
			cout << setw(setwN) << ' ';
		}
		if (isRchildBefore)
		{
			cout << setw(setwN - 1) << ' ';
		}
		else
		{
			cout << setw(setwN) << ' ';
		}
	}
	else
	{
		for (int i = 1; i<n; i++)
		{
			cout << setw(setwN) << ' ';
		}
		if (isRchildBefore)
		{
			cout << setw(setwN - 1) << a;
		}
		else
		{
			cout << setw(setwN) << a;
		}
	}

}

void outchar(string a, int n)
{
	for (int i = 1; i<n; i++)
	{
		cout << setw(setwN) << ' ';
	}
	cout << setw(setwN) << a;
}


void Routchar(char a, int n,bool isRchildBefore)
{
	for (int i = 1; i<n; i++)
	{
		cout << setw(setwN) << ' ';
	}
	if (isRchildBefore)
	{
		cout << setw(setwN - 2) << '(' << a << ')';
	}
	else
	{
		cout << setw(setwN - 1) << '(' << a << ')';
	}
}
void Routchar(string a, int n, bool isRchildBefore)
{
	if (a == "_")
	{
		for (int i = 1; i < n; i++)
		{
			cout << setw(setwN) << ' ';
		}
		if (isRchildBefore)
		{
			cout << setw(setwN - 2) << ' ' << ' ' << ')';
		}
		else
		{
			cout << setw(setwN - 1) << ' ' << ' '<< ' ';
		}
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			cout << setw(setwN) << ' ';
		}
		if (isRchildBefore)
		{
			cout << setw(setwN - 2) << '(' << a << ')';
		}
		else
		{
			cout << setw(setwN - 1) << '(' << a << ')';
		}
	}
}



int x[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
vector<int> v(15);
//int x[20]={223,12,221,33,632,7,8,921,1,11,123,13,23,1233,1,12,1234,23,12,34};


int main()
{
	int d=log((double)15)/log(2.0)+1;
	vector <string> s;
	int tot = 15;//tot应取3,7,15,31,63,127...
	for (int i = 0; i < tot; i++)
	{
		char tmp[1] = { 'A' + i-1 };
		string str;
		str += tmp[0];
		s.push_back(str);
	}

	s = { "1", "2", "3", "4", "5", "_", "7", "_", "9", "0", "1", "_", "_", "4", "_"};
	cout << endl << endl;
	printRBtree(s, tot);
	cout << endl << endl;
	rbNode *h;
	
	system("pause");
	return 1;
}



/**

输出示例：
0
:
.:::::::::::::::::::::::::::::::.
:                               :
1                               2
:                               :
.:::::::::::::::.               .:::::::::::::::.
:               :               :               :
3               4               5               6
:               :               :               :
.:::::::.       .:::::::.       .:::::::.       .:::::::.
:       :       :       :       :       :       :       :
7       8       9       :       ;       <       =       >
:       :       :       :       :       :       :       :
.:::.   .:::.   .:::.   .:::.   .:::.   .:::.   .:::.   .:::.
:   :   :   :   :   :   :   :   :   :   :   :   :   :   :   :
?   @   A   B   C   D   E   F   G   H   I   J   K   L   M   N
:   :   :   :   :   :   :   :   :   :   :   :   :   :   :   :
.:. .:. .:. .:. .:. .:. .:. .:. .:. .:. .:. .:. .:. .:. .:. .:.
: : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : :
O P Q R S T U V W X Y Z [ \ ] ^ _ ` a b c d e f g h i j k l m n






                     1
                     :
         .:::::::::::::::::::::::.
         :                       :
         2                       3
         :                       :
   .:::::::::::.                 ::::::.
   :           :                       :
  (4)          5                      (7)
   :           :                       :
   :::.     .:::::.                 .:::
      :     :     :                 :
      9    (0)    1                 4


                     A
                     :
         .:::::::::::::::::::::::.
         :                       :
         B                       C
         :                       :
   .:::::::::::.           .:::::::::::.
   :           :           :           :
  (D)          E           F          (G)
   :           :           :           :
.:::::.     .:::::.     .:::::.     .:::::.
:     :     :     :     :     :     :     :
H     I    (J)    K     L    (M)    N     O


*/

