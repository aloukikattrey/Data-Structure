#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
    map<int, list<int>> adj;
    queue<int> q;
    map<int, bool> visited;
    map<int, int> parent;

    void addEdge(int u, int v)
    {

        adj[u].push_back(v);

        adj[v].push_back(u);
    }
    void cycleDetection(int s)
    {
        int counter = 0;

        visited[s] = true;
        q.push(s);
        parent[s] = -1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto neighour : adj[node])
            {
                if (visited[neighour] == true && neighour != parent[node])
                {
                    cout << " Cycles exist";
                    return;
                }
                else if (!visited[neighour])
                {
                    q.push(neighour);
                    visited[neighour] = true;
                    parent[neighour] = node;
                }
            }
        }

        cout << " No Cycles exist";
    }
};

int main()
{
    Graph g;

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(3, 6);

    g.cycleDetection(1);

    return 0;
}