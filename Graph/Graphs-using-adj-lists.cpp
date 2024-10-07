#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
    map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction= 0-> undirected
        // direction= 1-> directed

        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void Print()
    {

        for (auto i : adj)
        {
            cout << i.first << " -> ";

            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(u, v, 1);
    gp.Addedge(1,2);
    gp.Addedge(2,3);
    gp.Addedge(2,4);
    gp.Addedge(3,4);

    g.Print();

    return 0;
}