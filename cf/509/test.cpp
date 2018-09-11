#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[25][25][15];
int a[25];
ll dfs(int pos,int cnt=0,int pre=0,bool limit=true)
{
    if(cnt>3)
        return 0;
    if(pos==-1)
    {
        //cout<<cnt<<endl;
        if(cnt<=3)
            return 1;
        else
            return 0;
    }
    if(!limit&&~dp[pos][cnt][pre])
        return dp[pos][cnt][pre];
    int up=limit? a[pos]:9;
    ll res=0;
    for(int i=0;i<=up;i++)
        res+=dfs(pos-1,cnt+(i!=0),i,limit&&i==a[pos]);
    if(!limit)
        dp[pos][cnt][pre]=res;
    return res;
}
ll go(ll x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    memset(dp,-1,sizeof(dp));
    cin>>T;
    while(T--)
    {
        ll L,R;
        cin>>L>>R;
        cout<<go(R)-go(L-1)<<endl;
    }
    return 0;
}
