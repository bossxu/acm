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
#include<map>
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int gcd(int a,int b)
{
  return b == 0?a:gcd(b,a%b);
}
struct Node
{
  int l,c;
}node[505];
map<int,int>q;
stack<pair<int,int> >sta;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n)
  {
    q.clear();
    for(int i = 1;i<=n;i++)
    {
      cin>>node[i].l;
    }
    for(int j = 1;j<=n;j++)
    {
      cin>>node[j].c;
    }
    int ans = node[1].l;
    for(int i = 2;i<=n;i++)
    {
      ans = gcd(node[i].l,ans);
    }
    if(ans!=1)
    {
      cout<<-1<<endl;
      continue;
    }
    for(int i = 1;i<=n;i++)
    {
      sta.push(make_pair(node[i].l,node[i].c));
      for(map<int,int>::iterator j=q.begin();j!=q.end();j++)
      {
        sta.push(make_pair(gcd(j->first,node[i].l),node[i].c+j->second));
      }
      while(!sta.empty())
      {
        if(q.count(sta.top().first))
        {
          q[sta.top().first] = min(q[sta.top().first],sta.top().second);
        }
        else
        q.insert(sta.top());
        sta.pop();
      }

    }
    cout<<q[1]<<endl;
  }
  return 0;
}
