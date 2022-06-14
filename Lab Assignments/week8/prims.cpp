#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
// #include<pair>
#include <climits>
using namespace std;
int main()
{
    int N , m;
    cout<<"enter total nodes and edges \n";
    cin>>N>>m;

    vector<pair<int,int> > adj[N]; 
    int v1, v2 ,wt;
    cout<<"enter nodes and weight\n";
    for(int i = 0 ; i<m ; i++)
    {
        cin>>v1>>v2>>wt;
        adj[v1].push_back({v2,wt});
        adj[v2].push_back({v1,wt});
    }
    

    int parent [N]; // to store the parent [-1,-1, -1,-1 ,.....]
    int key[N]; // to storde the weights or distances [0,inf,inf,inf,inf,....]
    bool mst[N]; // [F,F,F,F,F,.....]

    // intitialising 3 arrays
    for(int i = 0 ;i<N;i++)
    {
        // parent[i]=-1;
        key[i] = INT_MAX;
        mst[i] =false;
    }

    key[0] = 0;
    parent[0] = -1;

    // step1 - to find minimal val in key array - then index of that value 
    // step2 - for that index iterate through aj=djacent nodes 
    // update parent array and key array

    for(int count = 0 ; count<N-1;count++)
    {
        int minimal_in_key = INT_MAX ;
        int u ;

        for(int v = 0 ;v<N ;v++)
        {
            if(mst[v]== false && key[v]<minimal_in_key)
            {
                minimal_in_key = key[v];
                u= v;// index stored in u where we got the minimal value in key array 
            }
        }
        mst[u] = true;
        // now traversing through the adjacent nodes of minimal element 
        for(auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if(mst[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
            }
        }
    } 
        int min_mst_weight =0 ;

    for(int i= 1 ;i<N ;i++)
    {
        cout<<i << "- 's parent - " << parent[i]<<" - weight -"<< key[i] <<endl ;
        min_mst_weight +=key[i];
    }

    cout<<"total minimum weight = " << min_mst_weight;

}