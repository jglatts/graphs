#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include "graph.h"

using namespace std;

Graph::Graph(int v, int e) {
	this->verts = v;
	this->edges = e;
	for (int i = 0; i < verts; ++i) {
		adjList.insert(adjList.begin() + i, { -1 });
		dist.insert(dist.begin() + i, { -1 });
	}
}

void Graph::addEgde(int from, int to, int d) {
	adjList.at(from).push_back(to);
	dist.at(from).push_back(d);
}

void Graph::shortestPath(int source, int dest) {
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> cost;
	vector<bool> marked;
	for (int i = 0; i < verts; ++i) {
		marked.insert(marked.begin() + i, false);
		cost.insert(cost.begin() + i, INT_MAX);
	}
	pq.push(source);
	cost[source] = 0;
	while (!pq.empty()) {
		int node = pq.top();
		pq.pop();
		marked[node] = true;
		for (int i = 0; i < adjList[node].size(); ++i) {
			int neighbor = adjList[node].at(i);
			if (neighbor >= 0) {
				if (!marked[neighbor]) {
					int new_dist = cost.at(node) + dist.at(node).at(i);
					if (new_dist < cost.at(neighbor)) {
						cost.at(neighbor) = new_dist;
						pq.push(neighbor);
					}
				}
				else if (marked[neighbor] && neighbor == dest) break;
			}
 		}
	}
	cout << "Shortest Path From " << source << " to " << dest << ": " << cost.at(dest) << endl;
}

void Graph::bfs(int s) {
	queue<int> q;
	vector<bool> marked;
	for (int i = 0; i < verts; ++i) {
		marked.insert(marked.begin() + i, false);
	}
	q.push(s);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		marked[node] = true;
		cout << "Looking at " << node << " -> ";
		for (int i = 0; i < adjList[node].size(); ++i) {
			if (adjList[node].at(i) >= 0) {
				cout << adjList[node].at(i) << " ";
				if (!marked[adjList[node].at(i)]) {
					q.push(adjList[node].at(i));
					marked[adjList[node].at(i)] = true;
				}
			}
		}
		cout << " " << endl;
	}
}

void Graph::dfs(int s) {
	stack<int> st;
	vector<bool> marked;
	for (int i = 0; i < verts + 1; ++i) {
		marked.insert(marked.begin() + i, false);
	}
	st.push(s);
	while (!st.empty()) {
		int node = st.top();
		st.pop();
		marked[node] = true;
		cout << "Looking at " << node << " -> ";
		for (int i = 0; i < adjList[node].size(); ++i) {
			if (adjList[node].at(i) >= 0) {
				cout << adjList[node].at(i) << " ";
				if (!marked[adjList[node].at(i)]) {
					st.push(adjList[node].at(i));
					marked[adjList[node].at(i)] = true;
				}
			}
		}
		cout << " " << endl;
	}
}

void Graph::printGraph() {
	for (int i = 0; i < verts; ++i) {
		cout << i << " -> ";
		for (int j = 0; j < adjList.at(i).size(); ++j) {
			if (adjList[i].at(j) >= 0 )
				cout << "\t" << adjList[i].at(j) << " " << " weight: " << dist[i].at(j) << endl;
		}
		cout << "" << endl;
	}
}

void Graph::testGraph() {
	this->addEgde(0, 1, 3);
	this->addEgde(4, 3, 5);
	this->addEgde(0, 2, 10);
	this->addEgde(0, 3, 20);
	this->addEgde(2, 3, 3);
	this->addEgde(1, 2, 6);
	this->addEgde(3, 1, 4);
	this->bfs(0);
	cout << "" << endl;
	this->dfs(0);
	cout << "" << endl;
	this->printGraph();
	cout << "" << endl;
	this->shortestPath(0, 3);
}

