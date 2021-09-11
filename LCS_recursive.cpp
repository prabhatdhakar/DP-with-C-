#include<bits/stdc++.h>
using namespace std;
int max(int x,int y)
{
    return x>y?x:y;
}
int LCS(string X,string Y,int m,int n)
{
    int t[m+1][n+1];
    memset(t,-1,sizeof(t));

    if(n == 0 || m==0)
        return 0;
    if(t[m][n] != -1)
        return t[m][n];
    else
        if(X[m-1] == Y[n-1])
            return t[m][n] = 1 + LCS(X,Y,m-1,n-1);
        else
            return t[m][n] = max(LCS(X,Y,m-1,n),LCS(X,Y,m,n-1));

    return t[m][n];                    
}
int main()
{
    string X,Y;
    cout<<"Enter String 1 : ";
    cin>>X;
    cout<<"Enter String Y : ";
    cin>>Y;
    cout<<"The length of LCS is : "<<LCS(X,Y,X.length(),Y.length());
    return 0;
}