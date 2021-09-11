#include<bits/stdc++.h>
using namespace std;
bool t[100][100];
bool isSubsetSum(int arr[],int sum,int n)
{
    int i,j;
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
    return t[n][sum];                     
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
    cout<<"Enter sum : ";
    cin>>sum;
    cout<<"possible : "<<isSubsetSum(arr,sum,n);    
    return 0;
}