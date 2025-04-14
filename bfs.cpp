//Author: Abu Jafar Md Jakaria
//graph traversal using BFS
//print shortest path
//calculate the distance of each node from source node
#include<bits/stdc++.h>
using namespace std;

void bfs(int source, vector<vector<int>> &graph, vector<bool> &visited)
{
	queue<int> q;
	q.push(source);
	visited[source] = true;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		cout << u << " ";

		for(int i : graph[u])
		{
			if(!visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

void bfs_shortestPath(int source, int destination, vector<vector<int>> &graph, vector<int> &dist, vector<int> &parent)
{
	queue<int> q;
	q.push(source);
	dist[source] = 0;
	parent[source] = -1; //source node has no parent node

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		//cout << u << " ";

		for(int i : graph[u])
		{
			if(dist[i] == INT_MAX)
			{
				dist[i] = dist[u] + 1;
				parent[i] = u; //set parent of neighboring node
				q.push(i);

				if(i == destination) return;
			}
		}
	}
}

void printPath(int source, int destination, vector<int> &parent)
{
	vector<int> path;
	for(int node = destination; node != -1; node = parent[node])
		path.push_back(node);

	reverse(path.begin(), path.end());
	cout << "Path from " << source << "to " << destination << ":\n";
	for(int i: path)
		cout << i << " ";
	cout << endl;
}

int main()
{
	int nodes = 6;
	vector<vector<int>>graph(nodes);
	vector<bool> visited(nodes, false);
	vector<int> dist(nodes, INT_MAX);
    vector<int> parent(nodes, -1);

	//adjacency list
	graph[0] = {1, 2};
	graph[1] = {0, 3, 4};
	graph[2] = {0, 4};
	graph[3] = {1};
	graph[4] = {1, 2, 5};
	graph[5] = {4};
	bfs_shortestPath(0, 5, graph, dist, parent);

	// for (int i = 0; i < nodes; ++i)
	// {
	// 	cout << "Node " << i << ": " << dist[i] << endl;
	// }
	
	printPath(0, 5, parent);
	return 0;
}
