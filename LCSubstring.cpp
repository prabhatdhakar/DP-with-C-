#include<bits/stdc++.h>
using namespace std;

int LCS(string X,string Y,int m,int n)
{
    int i,j,max=0;
    int t[m+1][n+1];
    for(i=0;i<=m;i++)
        for(j=0;j<=n;j++)
            if(i == 0 || j == 0)
                t[i][j]=0;
           
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(X[i-1] == Y[j-1])
                t[i][j] = t[i-1][j-1] +1;
            else
                t[i][j] = 0;
        }     
    }    
    for(i=0;i<=m;i++)
        for(j=0;j<=n;j++)
        {
                if(t[i][j] >max)
                  max = t[i][j];
        }
    return max;                                   
}
int main()
{
    string X,Y;
    cout<<"Enter String X : ";
    cin>>X;
    cout<<"Enter String Y : ";
    cin>>Y;
    cout<<"The length of LCS is : "<<LCS(X,Y,X.length(),Y.length());
    return 0;
}