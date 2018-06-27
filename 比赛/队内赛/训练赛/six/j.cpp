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
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
char s[10];
int ans[27];
struct Node
{
  int item;
  ll num;
}node[27];
int vis[27];
int cmp(Node a,Node b)
{
  return a.num>b.num;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n)
  {
    for(int i = 0;i<26;i++)
    {
      node[i].item = i;
      node[i].num = 0;
    }
    clr(vis,0);
    for(int i =1;i<=n;i++)
    {
      cin>>s;
      int l = 1;
      int len = strlen(s);
      vis[s[0]-'a'] = 1;
      for(int j = len-1;j>=0;j--)
      {
        node[s[j]-'a'].num += l;
        l*=10;
      }
    }
    sort(node,node+26,cmp);
    for(int i = 0;i<26;i++)
    {
      if(!vis[node[i].item])
      {
        node[i].num = 0;
        break;
      }
    }
    ll ans = 0;
    int s = 1;
    sort(node,node+26,cmp);
    for(int i = 0;i<26;i++)
    {
      ans+=node[i].num*s;
      s++;
    }
    cout<<ans<<endl;
  }
  return 0;
}
