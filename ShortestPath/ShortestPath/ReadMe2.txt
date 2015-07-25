平行任务调度
时耗  必须在以下任务之前完成
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