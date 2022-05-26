#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n ;
     cout<<"entr size";
     
     cin>>n;
    int a[n];
    cout<<" enter " <<n << "elements";

    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>a[i];
    }

    int key ;
    cout<<"enter key";
    cin>>key;
    sort(a,a+n);
    int i = 0  , j = n-1 ;
    bool flag = false;
    while(i< j)
    {
        if(a[i] + a[j] < key)
        i++;
        else if(a[i] + a[j] > key)
        j--;
        else
        {
            cout<<"key found for pairs"<<a[i]  <<" "<<  a[j];
            flag =true;
            break;
        }

    }
    if(!flag)
    cout<<"no pair found";
    return 0;
}