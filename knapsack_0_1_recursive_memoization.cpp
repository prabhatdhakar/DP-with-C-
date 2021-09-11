#include <bits/stdc++.h>
using namespace std;
int t[100][100];
int max(int a,int b)
{
    return a>b ? a:b;
}
int knapsack(int wt[],int val[],int W,int n)
{
    if(n==0 || W==0)
        return 0;
    if(t[n][W] != -1)
        return t[n][W];
    else 
        if(wt[n-1] <= W)
            return t[n][W] = max(val[n-1] + knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
        else
            if(wt[n-1]>W)
                return t[n][W] = knapsack(wt,val,W,n-1);            
}
int main()
{
    int n,i,W,result;
    cout<<"Enter size of array : ";
    cin>>n;
    int wt[n],val[n];
    memset(t, -1, sizeof(t));
    cout<<"Enter weight array : ";
    for(i=0;i<n;i++)
        cin>>wt[i];
    cout<<"Enter value array : ";
    for(i=0;i<n;i++)
        cin>>val[i];
    cout<<"Enter max capacity(W) : ";
    cin>>W;    
    result = knapsack(wt,val,W,n);
    cout<<"Answer is "<<result;
    return 0;
}