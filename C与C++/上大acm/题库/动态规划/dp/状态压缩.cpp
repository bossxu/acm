#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod =1e8;
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
// 知识点分解：状态压缩 dp
const int N = 13, M =26;
int map[M],dp[N][M],st[M];
int n,m;
bool checkone(int x)//判断相邻的 是否有相同的
{
    return (x&(x<<1));
}
bool checktwo(int i,int x)//看是否匹配 
{
    return (map[i]&st[x]);
}
int main()
{
    while(cin>>n>>m)
    {
        clr(dp,0);
        clr(map,0);
        clr(st,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int a;
                cin>>a;
                if(!a)
                map[i] += (1<<(j-1));
            }
        }
        int k=0;
        for(int i=0;i<(1<<m);i++)
        {
            if(!checkone(i))
            {
                st[k++]=i;
            }
        }
        for(int i=0;i<k;i++)
        {
            if(!checktwo(1,i))
             {
                 dp[1][i]=1;
             }
        }
        for(int i=2;i<=n;i++)
        {
            for(int j = 0;j<k;j++)
            {
                if(checktwo(i,j))
                continue;
                for(int l=0;l<k;l++)
                {
                    if(checktwo(i-1,l))
                    continue;
                    if(!(st[j] & st[l]))
                    dp[i][j]+=dp[i-1][l];
                }
            }
        }
        ll ans=0;
        for(int i=0;i<=k;i++)
        {
            ans=(dp[n][i]+ans)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}