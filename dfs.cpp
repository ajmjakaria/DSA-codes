//DFS implementation
//Author: Abu Jafar Md Jakaria

#include<bits/stdc++.h>
using namespace std;

void dfs(int current_node, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[current_node] = true;
    cout << current_node << " ";

    //visit all the nodes
    for(int neighbor: graph[current_node])
    {
        if(!visited[neighbor])
             dfs(neighbor, graph, visited);
    }
}


void dfs_iterative(int current_node, vector<vector<int>> &graph, vector<bool> &visited)
{
    stack<int> st;
    st.push(current_node);

    while(!st.empty())
    {
        int neighbor = st.top();
        st.pop();

        if(!visited[neighbor]){
            visited[neighbor] = true;
            cout << neighbor << " ";

            //push the rest nodes at the stack
            for(auto it = graph[neighbor].rbegin(); it != graph[neighbor].rend(); ++it)
            {
                if(!visited[*it])
                    st.push(*it);
            }
        }
    }
}

void dfs_shortestPath(int current_node, int destination, vector<vector<int>> &graph, vector<bool> &visited,
    vector<int>&path, vector<int>&shortestPath, int &min_length) {
    visited[current_node] = true;
    path.push_back(current_node);

    //check if the destination is reached or not
    if(current_node == destination)
    {
        if(path.size() < min_length){
            min_length = path.size();
            shortestPath = path;
        }
    }
    else{
        //traverse the rest nodes

        for(int neighbor: graph[current_node])
        {
            if(!visited[neighbor]){
                dfs_shortestPath(neighbor, destination, graph, visited, path, shortestPath, min_length);
            }
        }
    }
    //backtrack
    path.pop_back();
    visited[current_node] = true;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes);
    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(nodes, false);
    int source, destination; cin >> source >> destination;
    // cout << "DFS traversal using recursion: ";
    // dfs(source, graph, visited);
    // cout << "\nDFS traversal using iterative approach: ";
    // dfs_iterative(source, graph, visited);

    vector<int>path;
    vector<int> shortestPath;
    int min_length = INT_MAX;
    dfs_shortestPath(source, destination, graph, visited, path, shortestPath, min_length);

    if(!shortestPath.empty())
    {
        cout << "Shotest Path: ";
        for(int i: shortestPath)
        {
            cout << i << " ";
        }
    }
    else cout << "There is no shortes path from " << source << "to " << destination << endl;

    return 0;
}
