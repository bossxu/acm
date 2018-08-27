#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
// 斜率dp，用的是一个单调队列维护下凸包；
// 感觉那个其实最难的点在于我们如何去更新那个双端队列里面的东西。
// 什么时候去头什么时候去尾，我们里面维护的是什么，这个都是斜率dp里面最为精髓的东西。
ll c[50005];
ll dp[50005];
int q[500005];
ll l;
int head,tail;
int p;
ll get(int i,int j)
{
  return dp[i]-dp[j]+c[i]*c[i]-c[j]*c[j]+2*p*(c[i]-c[j]);
}
int main()
{
  int n;
  while(cin>>n>>l)
  {
    c[0] = 0;
    for(int i=1;i<=n;i++)
    {
      cin>>c[i];
      c[i]+=c[i-1];
    }

    p = l+1;
    head = tail = 1;
    for(int i = 1;i<=n;i++)
    {
      c[i]+=i;
      while(head<tail && get(q[head+1],q[head])<2*c[i]*(c[q[head+1]]-c[q[head]])) head++;
      dp[i] = dp[q[head]]+(c[i]-c[q[head]]-p)*(c[i]-c[q[head]]-p);
      while(head<tail && get(q[tail],q[tail-1])*(c[i]-c[q[tail]]) > get(i,q[tail])*(c[q[tail]]-c[q[tail-1]])) tail--;
      q[++tail] = i;
    }
    cout<<dp[n]<<endl;
  }
  return 0;
}
