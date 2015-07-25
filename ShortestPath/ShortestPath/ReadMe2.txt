15
4 5 0.35   5 4 0.35   4 7 0.37
5 7 0.28   7 5 0.28   5 1 0.32
0 4 0.38   0 2 0.26   7 3 0.39
1 3 0.29   2 7 0.34   6 2 -1.20
3 6 0.52   6 0 -1.40   6 4 -1.25

ParallelTaskScheduling.cpp
平行任务调度
时耗  必须在以下任务之前完成
10
41.0   1 7 9
51.0   2
50.0
36.0
38.0
45.0
21.0   3 8
32.0   3 8
32.0   2
29.0   4 6
22 vertices, 41 edges
<V0>-->10[-41]
<V1>-->11[-51]
<V2>-->12[-50]
<V3>-->13[-36]
<V4>-->14[-38]
<V5>-->15[-45]
<V6>-->16[-21]
<V7>-->17[-32]
<V8>-->18[-32]
<V9>-->19[-29]
<V10>-->21[0]-->1[0]-->7[0]-->9[0]
<V11>-->21[0]-->2[0]
<V12>-->21[0]
<V13>-->21[0]
<V14>-->21[0]
<V15>-->21[0]
<V16>-->21[0]-->3[0]-->8[0]
<V17>-->21[0]-->3[0]-->8[0]
<V18>-->21[0]-->2[0]
<V19>-->21[0]-->4[0]-->6[0]
<V20>-->0[0]-->1[0]-->2[0]-->3[0]-->4[0]-->5[0]-->6[0]-->7[0]-->8[0]-->9[0]
<V21>
Start Time:
Task0 Time:0
Task1 Time:41
Task2 Time:123
Task3 Time:91
Task4 Time:70
Task5 Time:0
Task6 Time:70
Task7 Time:41
Task8 Time:91
Task9 Time:41
Finish time:173
请按任意键继续. . .

	vector<double> weight;
	vector<int> ntask;
	for (int i = 0; i < n; i++)
	{
		bool getWeight = true;
		double we;
		while (true)
		{
			int task;
			if (getWeight)
			{
				getWeight = false;
				scanf_s("%lf",&we);
				weight.push_back(we);
			}
			else
			{
				scanf_s("%d", &task);
				ntask.push_back(task);
			}
			if (getchar() == '\n')
				break;
		}
	}