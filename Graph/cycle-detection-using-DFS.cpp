// giving error

#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
    map<int, list<int>> adj;
    map<int, bool> visited;
    map<int, int> parent;

    void addEdge(int u, int v)
    {

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool detect(int node)
    {
        for (auto neighbour : adj[node])
        {
            if (visited[neighbour] == true && neighbour != parent[node])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                parent[neighbour] = node;
                visited[neighbour] = true;
                detect(neighbour);
            }
        }
        return false;
    }

    void cycleDetection(int node)
    {
        parent[node] = -1;

        if (detect(node);)
        {
            cout << "cycle exist";
        }
        else
        {
            cout << "cycle doesn't exist";
        }
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
