#include<bits/stdc++.h>
using namespace std;

int isSubsetSum(int arr[],int sum,int n)
{
    int i,j;
    bool t[n+1][sum+1];
    for(i=0;i<n+1;i++)
        for(j=0;j<sum+1;j++)
        {
            if(i==0)
                t[i][j] = false;
            if(j==0)
                t[i][j]  = true;
        }  
    for(i=1;i<n+1;i++)
        for(j=1;j<sum+1;j++)
        {          
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
        i = sum;
        while(i>=0)
        {
            if(t[n][i])
              return i;
            i--;
        } 
       // return 0;             
}
int minimumSubsetSumDiff(int arr[],int n)
{
    int i,s,range=0;
    for(i=0;i<n;i++)
        range += arr[i];
    s = isSubsetSum(arr,range/2,n);
    return (range-(2*s));
}
int main()
{
    int n,i,sum;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array : ";
    for(i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Minimum subset sum difference is : "<<minimumSubsetSumDiff(arr,n);    
    return 0;
}