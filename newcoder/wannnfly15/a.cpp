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
typedef unsigned long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int zu[100005];
struct node
{
  int num,price;
  bool operator <(const node &a) const{
    return price>a.price;
  }
}wei[100005];
int cmp1(int a,int b)
{
  return a>b;
}
int cmp2(node a, node b)
{
  return a.num>b.num;
}
priority_queue<node>q;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n,m;
  while(cin>>n>>m)
  {
    while(q.size()) q.pop();
    for(int i = 1;i<=n;i++)
    {
      cin>>zu[i];
    }
    for(int i = 1;i<=m;i++)
    {
      cin>>wei[i].num>>wei[i].price;
    }
    sort(zu+1,zu+n+1,cmp1);
    sort(wei+1,wei+m+1,cmp2);
    int flag = 1;
    int vis = 0;
    ll ans = 0;
    for(int i =1;i<=n;i++)
    {
      while(flag<=m && wei[flag].num>=zu[i])
      {
        q.push(wei[flag++]);
      }
      if(!q.size()) vis = 1;
      else
      {
        ans+=q.top().price;
        //cout<<q.top().price<<endl;
        q.pop();
      }
    }
    if(vis) cout<<-1<<endl;
    else  cout<<ans<<endl;
  }

  return 0;
}
