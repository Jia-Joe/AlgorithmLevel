#include "stdafx.h"

//优先级限制条件下并行任务调度的关键路径方法
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin >> n;//输入任务总数
	int s = 2 * n, t = 2 * n + 1;//任务的总起点，总终点
	vector<double> weight;
	vector<int> ntask;
	//每个任务k都有两个顶点Vsk->Vtk，顶点号k,k+n,权重为时长
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
				Edge eTask(i, i+n, we);
				g.addEdge(eTask);
			}
			else
			{
				scanf_s("%d", &task);
				ntask.push_back(task);
				Edge eTask(i+n,task,0.0);
				g.addEdge(eTask);
			}
			if (getchar() == '\n')
				break;
		}
	}
	g.print();


	system("pause");
	return 0;
}