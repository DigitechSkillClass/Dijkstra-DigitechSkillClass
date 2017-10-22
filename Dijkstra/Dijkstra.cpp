// Dijkstra.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <list>

#define I 3000
#define NUM_NODE 8
int aEdgeCost[NUM_NODE][NUM_NODE] =
{

	{ 0,1,I,I,I,I,I,6 },
	{ 1,0,2,I,I,I,4,I },
	{ I,2,0,5,I,I,I,I },
	{ I,I,5,0,3,I,1,I },
	{ I,I,I,3,0,2,I,I },
	{ I,I,I,I,2,0,4,2 },
	{ I,4,I,1,I,4,0,I },
	{ 6,I,I,I,I,2,I,0 },
};

int main()
{
	int aCost[NUM_NODE];
	bool aVisited[NUM_NODE];
	int aVia[NUM_NODE];
	for (int i = 0; i < NUM_NODE; i++)
	{
		aCost[i] = I;
		aVisited[i] = false;
		aVia[i] = -1;
	}

	int nStart = 5;
	int nDest = 1;
	aCost[nStart - 1] = 0;
	while (true)
	{
		int nMinCostNode = -1;
		int nMinCost = INT_MAX;
		for (int i = 0; i < NUM_NODE; i++)
		{
			if (aVisited[i] == true) continue;
			if (aCost[i] < nMinCost)
			{
				nMinCostNode = i;
				nMinCost = aCost[i];
			}
		}

		if (nMinCostNode < 0) break;

		aVisited[nMinCostNode] = true;

		for (int i = 0; i < NUM_NODE; i++)
		{
			if (aVisited[i] == true) continue;
			if (aCost[i] > aCost[nMinCostNode] + aEdgeCost[nMinCostNode][i])
			{
				aCost[i] = aCost[nMinCostNode] + aEdgeCost[nMinCostNode][i];
				aVia[i] = nMinCostNode;
			}
		}
	}

	std::list<int> lstPath;
	int nTempNode = nDest - 1;
	while (nTempNode + 1 != nStart)
	{
		lstPath.push_front(nTempNode);
		nTempNode = aVia[nTempNode];
	}
	lstPath.push_front(nStart - 1);
	for each(auto i in lstPath)
	{
		std::cout << i + 1 << std::endl;
	}

    return 0;
}

