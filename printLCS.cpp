#include<bits/stdc++.h>
using namespace std;
int max(int x,int y)
{
    return (x>y)?x:y;
}
int LCS(string X,string Y,int m,int n)
{
    string s;
    int i,j;
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
                t[i][j] = max(t[i-1][j],t[i][j-1]);
        }     
    }    
    i= m,j=n;
    while(i>0 && j>0)
    {
        if(X[i-1] == Y[j-1])
        {
            s.push_back(X[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i][j-1] > t[i-1][j])
                j--;
            else
                i--;    
        }
    }
    reverse(s.begin(),s.end());
    cout<<"The LCS is : "<<s<<endl;

    return t[m][n];                                   
}
int main()
{
    string X,Y;
    cout<<"Enter String X : ";
    cin>>X;
    cout<<"Enter String Y : ";
    cin>>Y;
    int ans = LCS(X,Y,X.length(),Y.length());
    cout<<"The length of LCS is : "<<ans;
    return 0;
}