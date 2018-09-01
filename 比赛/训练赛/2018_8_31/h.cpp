#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
typedef long long ll;
ll ans;
char s[maxn],t[maxn];
ll sum[maxn][30];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%s%s",s+1,t+1);
        int n=strlen(t+1);
        int m=strlen(s+1);
        for(int i=0;i<26;i++)
            sum[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<26;j++)
            {
                sum[i][j]=sum[i-1][j];
                if(t[i]=='a'+j)
                    sum[i][j]+=1;
            }
        }
        for(int i=1;i<=m;i++)
        {
            ans+=sum[n-m+i][s[i]-'a']-sum[i-1][s[i]-'a'];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
