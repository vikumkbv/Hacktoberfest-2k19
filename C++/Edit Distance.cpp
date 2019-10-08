#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		ll n=s1.length(),m=s2.length();
		ll dp[2][n+1];
		bool b;
		for(ll i=0;i<m+1;i++)
		{
			b=i&1;
			for(ll j=0;j<n+1;j++)
			{
				if(i==0 || j==0)
				dp[b][j]=max(i,j);
				else if(s1[i-1]==s2[j-1])
				dp[b][j]=dp[1-b][j-1];
				else
				dp[b][j]=1+min(dp[1-b][j-1],min(dp[1-b][j],dp[b][j-1]));
			}
		}
		cout<<dp[b][n]<<endl;
	}
}
