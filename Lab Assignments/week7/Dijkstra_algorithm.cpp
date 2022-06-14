 #include<bits/stdc++.h>
 
 using namespace std;
 void dijkstra( int graph[20][20] , int source,int n)
 {
     
     int distance[20];
     bool sssp[20];

     // initialising arrays
     for(int i = 1;i<=n;i++)
     {
         distance[i] = INT_MAX;
         sssp[i] =false;
     }

     distance[source] = 0;
    int c = 1;
    while(c<=n-1)
    {
        int min  = INT_MAX;
        int u = 0;
        for(int i = 1; i<=n;i++)
        {
            if(sssp[i] ==false && distance[i] < min)
            {
                min = distance[i];
                u= i;
            }
        }

        sssp[u]= true;

        for(int v = 1;v<=n ;v++)
        {
            if(graph[u][v]  && sssp[v] == false && distance[u] + graph[u][v] < distance[v] )
                {
                 distance[v] = distance[u] + graph[u][v] ;
                }
        }
        c++;

    }
        for(int i = 1 ;i<=n ;i++)
        {
            cout<<i<<"-"<<distance[i]<<"  \n";
        }

 }
 int main()
 {
    int n;
    cout<<"enter total number of nodes \n";
    cin>>n;


     int graph[20][20];
    cout<<"enter graph \n";
     for(int i =1 ;i<=n ;i++)
     {
         for(int j = 1;j<=n ;j++)
         {
             cin>>graph[i][j];
         }
         cout<<"\n";
     }
    int source;
    cout<<"enter source node from 1\n";
    cin>>source;

    dijkstra(graph,source,n);

 }


 