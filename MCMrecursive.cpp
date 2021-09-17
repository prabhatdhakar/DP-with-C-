#include<bits/stdc++.h>
using namespace std;
int MCM(int arr[],int i,int j)
{
    if(i>=j)
        return 0;
    int temp,min = INT_MAX;
    
    for(int k=i;k<j;k++)
    {
        temp = MCM(arr,i,k) + MCM(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);
        if(temp<min)
            min = temp;
    }    
    return min;
}
int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Entern array : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Minimum cost for this MCM is : "<<MCM(arr,1,n-1);    
}