#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int m , n ;
    cout<<"enter size of 2 arrays";
    cin>>m;
    cin>>n;

    int a[m];
    int b[n];
    cout<<"enter elements for 1st array \n";
    for (int i = 0; i < m; i++)
    {
        cin>>a[i];
    }
    cout<<"enter elements for 2nd array \n";
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    sort(a,a+m);
    sort(b,b+n);
    int i = 0 , j = 0;
    while(i<m && j<n )
    {
        if(a[i] == b[j])
        {
            cout<<a[i]<<"\t";
            i++;
            j++;  
        }
        else if(a[i] > b[j])
        {
            j++;
        }
        else if(a[i] < b[j])
        {
            i++;
        }
    }
    return 0;
}