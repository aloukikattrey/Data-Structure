// it is done by using bfs because bfs has ready made approach for the shortesh neibours while visiting
// we wiil be using parents DS for our answer

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

    void answer(int source, int destination)
    {

        vector<int> ans;
        int start = destination;
        ans.push_back(destination);

        while (start != source)
        {
            start = parent[start];

            ans.push_back(start);
        }
        reverse(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++)
        {

            cout << ans[i];

            if (i + 1 < ans.size())
            {
                cout << " -> ";
            }
        }
    }

    void shortestPath(int s, int d)
    {

        visited[s] = true;
        q.push(s);
        parent[s] = -1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto i : adj[node])
            {
                if (!visited[i])
                {
                    q.push(i);
                    parent[i] = node;
                    visited[i] = true;
                }
            }
        }
        answer(s, d);
    }
};

int main()
{
    Graph g;

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(1, 9);
    g.addEdge(9, 5);
    g.addEdge(1, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 5);

    g.shortestPath(2, 8);

    return 0;
}