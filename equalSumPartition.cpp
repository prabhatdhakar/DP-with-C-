#include<bits/stdc++.h>
using namespace std;
bool isSubsetSum(int arr[],int sum,int n)
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
    return t[n][sum];                     
}
int main()
{
    int i,n,sum=0;
    bool result;
    cout<<"Enter array size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array : ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
        sum += arr[i];
    if(sum%2 != 0)
        result = false;
    else
        result = isSubsetSum(arr,sum/2,n);
    cout<<"Result : "<<result;                    
    return 0;
}