#include "stdafx.h"

#include "AcyclicSP.h"

//���ȼ����������²���������ȵĹؼ�·������
int _tmainPTS(int argc, _TCHAR* argv[])
{
	int n;
	cin >> n;//������������
	int s = 2 * n, t = 2 * n + 1;//���������㣬���յ�
	vector<double> weight;
	vector<int> ntask;
	//ÿ������k������������Vsk->Vtk�������k,k+n,Ȩ��Ϊʱ��
	EdgeWeightedDigraph g(2*n+2);
	for (int i = 0; i < n; i++)
	{
		Edge es(s, i, 0.0), et(i + n, t, 0.0);
		g.addEdge(es);
		g.addEdge(et);
		bool getWeight = true;
		double we;
		while (true)
		{
			int task;
			if (getWeight)
			{
				getWeight = false;
				scanf_s("%lf",&we);
				Edge eTask(i, i+n, -we);
				g.addEdge(eTask);
			}
			else
			{
				scanf_s("%d", &task);
				Edge eTask(i+n,task,0.0);
				g.addEdge(eTask);
			}
			if (getchar() == '\n')
				break;
		}
	}
	g.print();
	AcyclicSP nlp(g, s);
	for (int i = 0; i < n; i++)
	{
		int k = -nlp.disToV(i);
		printf("Task%d Time:%d\n",i,k);
	}
	int ftime=-nlp.disToV(t);
	printf("Finish time:%d\n",ftime);
	system("pause");
	return 0;
}