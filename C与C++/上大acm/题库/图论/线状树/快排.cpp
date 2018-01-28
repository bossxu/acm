
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
const double eps = 1e-6;
// 知识点分解：树状数组
const int maxn= 500005;
struct st{
    int num,index;
}node[maxn];
int t[maxn],c[maxn];
int n;
int cmp(st a, st b)
{
    return a.num<b.num;
}
int lowbit(int x)
{
    return x&(-x);
}
void change(int x,int p)//将第x个数加p 
{
    while(x<=n)
    {
        t[x]+=p;
        x+=lowbit(x);
    }
    return;
}
int sum(int k)//前k个数的和 
{
    int ans=0;
    while(k>0)
    {
        ans+=t[k];
        k-=lowbit(k);
    }
    return ans;
}
int main()
{
    while(cin>>n && n)
    {
      for(int i=1;i<=n;i++)
      {
          cin>>node[i].num;
          node[i].index=i;
      }
      sort(node+1,node+n+1,cmp);
      for(int i=1;i<=n;i++)
      {
          c[node[i].index]=i;
      }
      ll s=0;
      clr(t,0);
      for(int i=1;i<=n;i++)
      {
         change(c[i],1);
         s+=c[i]-sum(c[i]);
      }
      cout<<s<<endl;
    }
    return 0;
}