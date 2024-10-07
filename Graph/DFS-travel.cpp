// recursive method

#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
    map<int, list<int>> adj;
    map<int, bool> visited;

    void addEdge(int u, int v)
    {

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int node)
    {
        cout << node << " ";
        visited[node] = true;
        for (int i : adj[node])
        {
            if (!visited[i])
            {
                DFS(i);
            }
        }
    }
};
int main()
{
    Graph g;

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.DFS(2);
    return 0;
}
