#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool check_bipartite_bfs(int node, vector<int> adj[], int color[])
{
    queue<int> q;
    color[node] = 1;
    q.push(node);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        for (auto child : adj[vertex])
        {
            if (color[child] == -1)

            {
                color[child] = 1 - color[vertex];
                q.push(child);
            }
            else if(color[child] == color[vertex])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    cout << "enter number of nodes and edges \n";
    int n, e;
    cin >> n >> e;
    vector<int> adj[n+1];

    cout << "enter " << e << "edges \n";
    for (int i = 1; i <= e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);

    }

    int color[n+1] ;
    for(int i=0;i<=n;i++){
        color[i]=-1;
    }
    bool res=false;
    for (int i = 1; i <=n; i++)
    {
        if (color[i] == -1)
        {
            res = check_bipartite_bfs(i, adj, color);
            if (res)
            {
                cout << "the graph is bipartite";
                
            }
            else
            {
                cout << "not a bipartite";
            }
        }
    }
    return 0 ;
}

