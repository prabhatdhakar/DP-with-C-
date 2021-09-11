#include<bits/stdc++.h>
using namespace std;

long countSubsetSum(int a[], int sum, int n)
{
    long tab[n + 1][sum + 1];
    tab[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        tab[0][i] = 0;
    for (int i = 1; i <= n; i++)
        tab[i][0] = 1;
  
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] > j)
                tab[i][j] = tab[i - 1][j]%1000000007;
            else
                tab[i][j] = ((tab[i - 1][j]%1000000007) + (tab[i - 1][j - a[i - 1]]%1000000007))%1000000007;
        }
    }
  
    return (tab[n][sum]);
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
    cout<<"count : "<<countSubsetSum(arr,sum,n);    
    return 0;
}