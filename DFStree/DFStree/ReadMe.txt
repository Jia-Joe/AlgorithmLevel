﻿************ NoRecur DFS ************
23
0 1 1.0
0 7 2
0 12 3
0 13 4
0 15 5
1 2 6
1 4 7
1 6 8
1 7 9
2 3 1
2 5 1.1
2 6 1.2
3 4 1.3
3 5 1.4
7 8 1.5
8 9 1.6
8 10 1.7
8 11 1.8
9 10 1.9
9 11 2.0
12 13 2.1
13 14 2.2
13 15 2.5

<V0>--1[1]--7[2]--12[3]--13[4]--15[5]
<V1>--0[1]--2[6]--4[7]--6[8]--7[9]
<V2>--1[6]--3[1]--5[1.1]--6[1.2]
<V3>--2[1]--4[1.3]--5[1.4]
<V4>--1[7]--3[1.3]
<V5>--2[1.1]--3[1.4]
<V6>--1[8]--2[1.2]
<V7>--0[2]--1[9]--8[1.5]
<V8>--7[1.5]--9[1.6]--10[1.7]--11[1.8]
<V9>--8[1.6]--10[1.9]--11[2]
<V10>--8[1.7]--9[1.9]
<V11>--8[1.8]--9[2]
<V12>--0[3]--13[2.1]
<V13>--0[4]--12[2.1]--14[2.2]--15[2.5]
<V14>--13[2.2]
<V15>--0[5]--13[2.5]
************ NoRecur DFS ************
23
0 7 2
7 8 1.5
8 9 1.6
9 11 2.0
12 13 2.1
8 10 1.7
0 12 3
0 13 4
0 15 5
1 2 6
1 4 7
1 6 8
1 7 9
2 3 1
2 5 1.1
0 1 1.0
2 6 1.2
9 10 1.9
3 4 1.3
3 5 1.4
8 11 1.8
13 14 2.2
13 15 2.5

0 7 8 9 11 10 1 2 4 3 5 6 12 13 14 15 

2
0 1 2.0
0 2 3.0

8
0 5 1
2 4 1
2 3 1
1 2 1
0 1 1
3 4 1
3 5 1
0 2 1