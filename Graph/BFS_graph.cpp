#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
    map<int, list<int>> adj;
    queue<int> q;
    map<int, bool> visited;

    void addEdge(int u, int v)
    {

        adj[u].push_back(v);

        adj[v].push_back(u);
    }
    void BFS(int s)
    {

        visited[s] = true;
        q.push(s);

        while (!q.empty())
        {
            int node = q.front();
            cout << node;
            q.pop();
            for (auto i : adj[node])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}