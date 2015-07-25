#include "stdafx.h"


#include "BellmanFord.h"


BellmanFordSP::BellmanFordSP(EdgeWeightedDigraph &G, int s)
{
	this->s = s;
	cost = 0;
	for (int i = 0; i < G.Vget(); i++)
	{
		Edge newE(0, 0, INF);
		edgeTo.push_back(newE);
		distTo.push_back(INF);
		onQ.push_back(false);
	}
	distTo[s] = 0.0;
	//Edge e0(s, s, 0.0);
	//edgeTo[s] = e0;
	queue.push(s);
	onQ[s] = true;

	while (!queue.empty()&&!this->hasNegtiveCycle())
	{
		int v = queue.front();
		queue.pop();
		onQ[v] = false;
		relax(G, v);
	}
}
void BellmanFordSP::relax(EdgeWeightedDigraph &G, int v)
{
	for (Edge e : G.adjGet(v))
	{
		int w = e.to();
		if (distTo[w] > distTo[v] + e.weightGet())
		{
			distTo[w]=distTo[v] + e.weightGet();
			edgeTo[w] = e;
			if (!onQ[w])
			{
				queue.push(w);
				onQ[w] = true;
			}
			if (cost++%G.Vget() == 0)
				findNegativeCycle();
		}
	}
}
void BellmanFordSP::findNegativeCycle()
{
	int Ve = edgeTo.size();
	EdgeWeightedDigraph spt(Ve);
	for (int v = 0; v < Ve; v++)
	{
		if (edgeTo[v].weightGet() != INF)
			spt.addEdge(edgeTo[v]);
	}
	FindCycle fc(spt);
	cycle = fc.getCycle();
}
bool BellmanFordSP::hasNegtiveCycle()
{
	return !cycle.empty();
}
vector<int> BellmanFordSP::negtiveCycle()
{
	return cycle;
}

void BellmanFordSP::printPathTo(int v)
{
	if (!hasPathTo(v))
		cout << "No path to " << v << endl;
	else
	{
		cout << "[V" << s << "->V" << v << " (" << setw(4) << distTo[v] << setw(3) << ")] " << s;
		stack<int> path;
		int x = v;
		do
		{
			path.push(x);
			x = edgeTo[x].from();
		} while (edgeTo[x].to() != s);
		int pathSize = path.size();
		if (v != s)
		{
			for (int i = 0; i < pathSize; i++)
			{
				cout << "-->" << path.top();
				path.pop();
			}
		}
		cout << endl;
	}

}



int _tmain(int argc, _TCHAR* argv[])
{
	EdgeWeightedDigraph g(8);
	int E;
	cin >> E;
	for (int i = 0; i < E; i++)
	{
		int v, w;
		double we;
		cin >> v >> w >> we;
		Edge e(v, w, we);
		g.addEdge(e);
	}
	g.print();
	cout << endl << "The Shortest Paths:" << endl;
	BellmanFordSP bfsp(g, 0);
	if (bfsp.hasNegtiveCycle())
	{
		cout << "Has negtive cycle!" << endl;
		//for (int i : bfsp.negtiveCycle())
		//	cout << i << "-->";
		//cout << endl;
	}
	else
	{
		for (int i = 0; i < g.Vget(); i++)
			bfsp.printPathTo(i);
	}

	system("pause");
	return 0;
}
