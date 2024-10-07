// non recursive method
#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
    map<int, list<int>> adj;
    map<int, bool> visited;
    stack<int> st;

    //creating adjacency list

    void addEdge(int u, int v)
    {

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    

    int unvisited_neighbour(int v)
    {
        for (auto i : adj[v])
        {
            if (!visited[i])
            {
                return i;
            }
        }
        return -1;
    }

    void DFS(int node)
    {

        st.push(node);
        cout << node << " ";
        visited[node] = true;

        while (!st.empty())
        {
            int ele = st.top();

            int padosi = unvisited_neighbour(ele);
            if (padosi == -1)
            {
                st.pop();
            }
            else
            {
                st.push(padosi);
                cout << padosi << " ";
                visited[padosi] = true;
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
