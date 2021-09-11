#include<bits/stdc++.h>
using namespace std;
int min(int x,int y)
{
    return x<y?x:y;
}
int coinChange(int wt[],int W,int n)
{
    int t[n+1][W+1];
    int i,j;
    for(i=0;i<W+1;i++)
        t[0][i] = INT_MAX-1;
    for(j=1;j<n+1;j++)
        t[j][0] = 0;  
    for(j=1;j<W+1;j++)
        if(j%wt[0] == 0)
            t[1][j] = j/wt[0];
        else
            t[1][j] = INT_MAX-1;           

    for(i=2;i<n+1;i++)
        for(j=1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
                t[i][j] = min(t[i][j-wt[i-1]] + 1, t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
        if(t[n][W] == INT_MAX-1)
            return -1;
        return t[n][W];
}
int main()
{
    int n,i,j,W;
    int wt[100];
    cout<<"Enter size of array : ";
    cin>>n;

    cout<<"Enter coin array : ";
    for(i=0;i<n;i++)
        cin>>wt[i];
    
    cout<<"Enter Sum val : ";
    cin>>W;    
    
    cout<<"Minimum number of coin is "<<coinChange(wt,W,n);
    return 0;
}