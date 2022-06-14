#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    int graph[20][20];
    cout<<"Enter matrix: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    
    int distance[20];

    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
    }

    distance[0]=0;

    int c=0;
    while(c<n-1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j] && distance[i]+graph[i][j]<distance[j]){
                    distance[j]=distance[i]+graph[i][j];
                }
            }
        }
       c++;
    }
    int flag=0;
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j] && distance[i]+graph[i][j]<distance[j]){
                    cout<<"Negetive Cycle exist";
                    flag=1;
                    break;
                }
            }
        }
    if(flag==0)
    for(int i=1;i<n;i++){
        cout<<i+1<<"-"<<distance[i]<<"  \n";
    }
}