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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
//很神奇的是只要一个符合的答案就行
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int w;
    int n;
    int v[22];
    int dp[10005];
    int head[10005];
    while(cin>>w>>n)
    {
      for(int i=1;i<=n;i++)
      {
        cin>>v[i];
      }
      clr(dp,0);
      clr(head,0);
      dp[0]=0;
      for(int i=1;i<=n;i++)
      {
        for(int j=w;j>=v[i];j--)
        {
          if(dp[j]<dp[j-v[i]]+v[i])
          {
            dp[j]=dp[j-v[i]]+v[i];
            head[j]=v[i];
            //printf("j--%dhead[j]--%d\n",j,head[j]);
          }
        }
      }
      while(w>=1 && dp[w]==dp[w-1])
      {
        w--;
      }
      int k = dp[w];
      int c[20];
      int l=0;
      while(head[k]!=0)
      {
        c[l++]=head[k];
        k-=head[k];
      }
      for(int i=l-1;i>=0;i--)
      {
        printf("%d ",c[i]);
      }
      cout<<"sum:"<<dp[w]<<endl;
    }
    return 0;
}
