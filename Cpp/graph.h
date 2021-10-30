#ifndef GRAPH__H
#define GRAPH__H

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

class Graph
{
public:
	Graph(int, int);
	void addEgde(int, int, int);
	void testGraph();
	void bfs(int);
	void dfs(int);
	void shortestPath(int, int);
	void printGraph();

private:
	int verts;
	int edges;
	std::vector<std::vector<int>> adjList;
	std::vector<int> dist;
};

#endif // !GRAPH__H
