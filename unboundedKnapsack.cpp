//SAME PROGRAM WORKS FOR ROD CUTTING
#include<bits/stdc++.h>
using namespace std;

int max(int x,int y)
{
    return x > y ? x:y;
}
int knapsack(int wt[],int val[],int W,int n)
{
    int t[n+1][W+1];
    int i,j;
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<W+1;j++)
            if(i==0 || j==0)
                t[i][j] = 0;            
    }
    for(i=1;i<n+1;i++)
        for(j=1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
                t[i][j] = max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
        return t[n][W];
}
int main()
{
    int n,i,j,W;
    int wt[100],val[100];
    cout<<"Enter size of array : ";
    cin>>n;

    cout<<"Enter weight array : ";
    for(i=0;i<n;i++)
        cin>>wt[i];
    cout<<"Enter value array : ";
    for(i=0;i<n;i++)
        cin>>val[i];
    cout<<"Enter max capacity(W) : ";
    cin>>W;    
    
    cout<<"Answer is "<<knapsack(wt,val,W,n);
    return 0;
}