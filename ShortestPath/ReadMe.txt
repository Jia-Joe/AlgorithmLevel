﻿File content

1.Edge Weighted Digraph-->Relax-->Shortest Path

2.MinIndex Priority Queue-->Dijkstra Algorithm

3.Topological Sort-->Acyclic Longest Path-->Parallel Task Scheduling

4.Find Negative Cycle-->Bellman-Ford Algorithm


BellmanFordSP.cpp
15
4 5 0.35   5 4 0.35   4 7 0.37
5 7 0.28   7 5 0.28   5 1 0.32
0 4 0.38   0 2 0.26   7 3 0.39
1 3 0.29   2 7 0.34   6 2 -1.20
3 6 0.52   6 0 -1.40   6 4 -1.25
8 vertices, 15 edges
<V0>-->4[0.38]-->2[0.26]
<V1>-->3[0.29]
<V2>-->7[0.34]
<V3>-->6[0.52]
<V4>-->5[0.35]-->7[0.37]
<V5>-->4[0.35]-->7[0.28]-->1[0.32]
<V6>-->2[-1.2]-->0[-1.4]-->4[-1.25]
<V7>-->5[0.28]-->3[0.39]

The Shortest Paths:
[V0->V0 (   0)] 0
[V0->V1 (0.93)] 0-->2-->7-->3-->6-->4-->5-->1
[V0->V2 (0.26)] 0-->2
[V0->V3 (0.99)] 0-->2-->7-->3
[V0->V4 (0.26)] 0-->2-->7-->3-->6-->4
[V0->V5 (0.61)] 0-->2-->7-->3-->6-->4-->5
[V0->V6 (1.51)] 0-->2-->7-->3-->6
[V0->V7 ( 0.6)] 0-->2-->7


15
4 5 0.35   5 4 -0.66   4 7 0.37
5 7 0.28   7 5 0.28   5 1 0.32
0 4 0.38   0 2 0.26   7 3 0.39
1 3 0.29   2 7 0.34   6 2 0.40
3 6 0.52   6 0 0.58   6 4 0.93
8 vertices, 15 edges
<V0>-->4[0.38]-->2[0.26]
<V1>-->3[0.29]
<V2>-->7[0.34]
<V3>-->6[0.52]
<V4>-->5[0.35]-->7[0.37]
<V5>-->4[-0.66]-->7[0.28]-->1[0.32]
<V6>-->2[0.4]-->0[0.58]-->4[0.93]
<V7>-->5[0.28]-->3[0.39]

The Shortest Paths:
Has negtive cycle!


========================================

DijkstraAllPairSP.cpp

15
4 5 0.35   5 4 0.35   4 7 0.37
5 7 0.28   7 5 0.28   5 1 0.32
0 4 0.38   0 2 0.26   7 3 0.39
1 3 0.29   2 7 0.34   6 2 0.40
3 6 0.52   6 0 0.58   6 4 0.93

8 vertices, 15 edges
<V0>-->4[0.38]-->2[0.26]
<V1>-->3[0.29]
<V2>-->7[0.34]
<V3>-->6[0.52]
<V4>-->5[0.35]-->7[0.37]
<V5>-->4[0.35]-->7[0.28]-->1[0.32]
<V6>-->2[0.4]-->0[0.58]-->4[0.93]
<V7>-->5[0.28]-->3[0.39]



The Shortest Paths:


Start From V0:

[V0->V0 (   0)] 0
[V0->V1 (1.05)] 0-->4-->5-->1
[V0->V2 (0.26)] 0-->2
[V0->V3 (0.99)] 0-->2-->7-->3
[V0->V4 (0.38)] 0-->4
[V0->V5 (0.73)] 0-->4-->5
[V0->V6 (1.51)] 0-->2-->7-->3-->6
[V0->V7 ( 0.6)] 0-->2-->7

Start From V1:

[V1->V0 (1.39)] 1-->3-->6-->0
[V1->V1 (   0)] 1
[V1->V2 (1.21)] 1-->3-->6-->2
[V1->V3 (0.29)] 1-->3
[V1->V4 (1.74)] 1-->3-->6-->4
[V1->V5 (1.83)] 1-->3-->6-->2-->7-->5
[V1->V6 (0.81)] 1-->3-->6
[V1->V7 (1.55)] 1-->3-->6-->2-->7

Start From V2:

[V2->V0 (1.83)] 2-->7-->3-->6-->0
[V2->V1 (0.94)] 2-->7-->5-->1
[V2->V2 (   0)] 2
[V2->V3 (0.73)] 2-->7-->3
[V2->V4 (0.97)] 2-->7-->5-->4
[V2->V5 (0.62)] 2-->7-->5
[V2->V6 (1.25)] 2-->7-->3-->6
[V2->V7 (0.34)] 2-->7

Start From V3:

[V3->V0 ( 1.1)] 3-->6-->0
[V3->V1 (1.86)] 3-->6-->2-->7-->5-->1
[V3->V2 (0.92)] 3-->6-->2
[V3->V3 (   0)] 3
[V3->V4 (1.45)] 3-->6-->4
[V3->V5 (1.54)] 3-->6-->2-->7-->5
[V3->V6 (0.52)] 3-->6
[V3->V7 (1.26)] 3-->6-->2-->7

Start From V4:

[V4->V0 (1.86)] 4-->7-->3-->6-->0
[V4->V1 (0.67)] 4-->5-->1
[V4->V2 (1.68)] 4-->7-->3-->6-->2
[V4->V3 (0.76)] 4-->7-->3
[V4->V4 (   0)] 4
[V4->V5 (0.35)] 4-->5
[V4->V6 (1.28)] 4-->7-->3-->6
[V4->V7 (0.37)] 4-->7

Start From V5:

[V5->V0 (1.71)] 5-->1-->3-->6-->0
[V5->V1 (0.32)] 5-->1
[V5->V2 (1.53)] 5-->1-->3-->6-->2
[V5->V3 (0.61)] 5-->1-->3
[V5->V4 (0.35)] 5-->4
[V5->V5 (   0)] 5
[V5->V6 (1.13)] 5-->1-->3-->6
[V5->V7 (0.28)] 5-->7

Start From V6:

[V6->V0 (0.58)] 6-->0
[V6->V1 (1.34)] 6-->2-->7-->5-->1
[V6->V2 ( 0.4)] 6-->2
[V6->V3 (1.13)] 6-->2-->7-->3
[V6->V4 (0.93)] 6-->4
[V6->V5 (1.02)] 6-->2-->7-->5
[V6->V6 (   0)] 6
[V6->V7 (0.74)] 6-->2-->7

Start From V7:

[V7->V0 (1.49)] 7-->3-->6-->0
[V7->V1 ( 0.6)] 7-->5-->1
[V7->V2 (1.31)] 7-->3-->6-->2
[V7->V3 (0.39)] 7-->3
[V7->V4 (0.63)] 7-->5-->4
[V7->V5 (0.28)] 7-->5
[V7->V6 (0.91)] 7-->3-->6
[V7->V7 (   0)] 7



AcyclicSP.cpp
13
5 4 0.35   4 7 0.37   5 7 0.28
5 1 0.32   4 0 0.38   0 2 0.26
3 7 0.39   1 3 0.29   7 2 0.34
6 2 0.40   3 6 0.52   6 0 0.58
6 4 0.93
8 vertices, 13 edges
<V0>-->2[0.26]
<V1>-->3[0.29]
<V2>
<V3>-->7[0.39]-->6[0.52]
<V4>-->7[0.37]-->0[0.38]
<V5>-->4[0.35]-->7[0.28]-->1[0.32]
<V6>-->2[0.4]-->0[0.58]-->4[0.93]
<V7>-->2[0.34]

The Shortest Paths:
[V3->V0 ( 1.1)] 3-->6-->0
No path to 1
[V3->V2 (0.73)] 3-->7-->2
[V3->V3 (   0)] 3
[V3->V4 (1.45)] 3-->6-->4
No path to 5
[V3->V6 (0.52)] 3-->6
[V3->V7 (0.39)] 3-->7