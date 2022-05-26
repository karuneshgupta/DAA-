//  CHECK THIS LINK FOR DESCRIPTION 
// https://www.youtube.com/watch?v=uzVUw90ZFIg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12

#include<iostream>
using namespace std;
#include<vector>
#include<list>
const int N= 1e5+10;
// WILL MAINTAIN 2 ARRAYS VISITED AND DFSVISITED 
// MARKING THEM AT SAME TIME FOR THE NODE 


bool check_for_cycle(int node , vector<int> adj[] , int vis[] , int dfsvis[] );
bool is_cyclic(int n , vector<int> adj[]);
void DFS(int vertex);
int main()
{
    vector <int> adj[N];
    int n , m ; // n = num of nodes , m = num of edges
    cout<<"enter number of nodes and edges\n";
    cin>>n>>m;
   
    cout<<"enter nodes to join \n";
    for(int i = 1 ; i <=m  ;i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2); 
    }

    // calling is_cyclic function

    bool result = is_cyclic(n,adj); 
    if(result)
    cout<<"cycle exists";
    else{
        cout<<"cycle doesnt exists";
    }

}

bool check_for_cycle(int node , vector<int> adj[] , int vis[] , int dfsvis[] )
{
    vis[node] = 1;
    dfsvis[node] =1;

    for(auto child : adj[node])
    {
        if(!vis[child])
        {
            if(check_for_cycle(child, adj,vis,dfsvis))
            return true;// cycle exists 
        }

        else if(dfsvis[child])
        {
            // cycle exists also if for that particular node(child) 
            // in vis and dfsvis array it is marked 1  
           return true;
        }
    }

    // cycle doesnt exists in whole of the graph
    // while returning back in recursion tree 
    // marking that node unvisited = (0) in dfsvis array since it is directed graph
    dfsvis[node] = 0;
    return false;
}

bool is_cyclic(int n , vector<int> adj[])
{
    int vis[n]  , dfsvis[n] ;

    // checking or calling cycle for each node 
    // as graph can have many components 
    // and for more check the video
    bool res;
    for(int i = 1 ; i <=n ;i++)
    {
        if(!vis[i]){
             res = check_for_cycle(i , adj , vis,dfsvis);
            if(res) 
            {
            return true;
            }
        }
    }

    // no cycle present 
    return false ;
}