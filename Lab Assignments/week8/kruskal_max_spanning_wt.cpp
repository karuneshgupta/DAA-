#include <bits/stdc++.h>
using namespace std;
class edge{
    public:
        int source;
        int dest;
        int weight;
};
bool comparator(edge e1 , edge e2){
    return e2.weight<e1.weight;// for descending
}
int findparent(int v,int parent[]){
    if(v==parent[v])return v;
    return findparent(parent[v],parent);
}
void krushkal(edge *input , int n, int e){
    sort(input,input+e,comparator);
    edge *output=new edge[n-1];
    int i=0,c=0;
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    while(c<n-1){
        edge current=input[i];
        int sourceparent=findparent(current.source,parent);
        int destparent=findparent(current.dest,parent);
        if(sourceparent!=destparent){
            parent[current.dest]=current.source;
            output[c]=current;
            c++;
        }
        i++;
    }
    int total_mst_weight = 0;
    for(int i=0;i<n-1;i++){
        cout<<output[i].weight<<" ";
        total_mst_weight += output[i].weight;
        
    }
cout<<"\nweight = " << total_mst_weight; 
}
int main()
{
    cout << "enter number of nodes and edges \n";
    int n, e;
    cin >> n >> e;
    //discription about edge in input array that will
    //contain info. of each edge i.e source , destination ,weight
     edge *input=new edge[e];

     for(int i=0;i<e;i++){
         int s,w,d;
         cin>>s>>d>>w;
         input[i].source=s;
         input[i].dest=d;
         input[i].weight=w;
     }
     krushkal(input,n,e);
    return 0 ;
}

