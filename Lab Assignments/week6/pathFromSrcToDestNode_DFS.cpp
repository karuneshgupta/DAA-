#include<iostream>
using namespace std;
#include<vector>
#include<list>
const int N= 1e5+10;
vector <int> adj[N];
vector<bool>visited(N);
int flag = 0 ;
void DFS(int vertex, int);
int main()
{
    int n , m ; // n = num of nodes , m = num of edges
    cout<<"enter number of nodes and edges\n";
    cin>>n>>m;
   

    cout<<"enter nodes to join \n";
    for(int i = 1 ; i <=m  ;i++)
    {
        int v1, v2;
        cin>>v1>>v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    int source  , destination;
    cout<<"enter starting and ending node\n";
    cin>>source>>destination;
    DFS(source , destination);

    if(flag)
    {
        cout<<"\n path exists";
    }
    else{
        cout<<"\n path doesnt exists";
    }
    return  0; 
}


void DFS(int vertex, int destination)
{

 if(visited[vertex]) return; // base condition
 
 if(visited[destination]) 
 {
     flag = 1;
     return ;
 }


 visited[vertex] = true ;
 cout<<vertex<<" ";
 for(auto child : adj[vertex])
 {
     DFS(child,destination);
 }
}
