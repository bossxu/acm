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
struct Node
{
  int x,y;
}node[100005];
bool cmp1(Node a,Node b)
{
  if(a.x==b.x)
  {
    return a.y<b.y;
  }
  return a.x<b.x;
}
bool cmp2(Node a,Node b)
{
  if(a.x==b.x)
  {
    return a.y>b.y;
  }
  return a.x<b.x;
}
int tot;
int all[100005];
template<class Cmp>
int LIS (Cmp cmp)
{
  static int m, end[100005];
  m = 0;
  for (int i=0;i<tot;i++)
  {
      int pos = lower_bound(end, end+m, all[i], cmp)-end;
      end[pos] = all  [i], m += pos==m;
  }
  return m;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while(cin>>n)
  {
    Node st,en;
    cin>>st.x>>st.y>>en.x>>en.y;
    if(st.x>en.x)
      swap(st,en);
    //cout<<st.x<<" "<<st.y<<" "<<en.x<<" "<<en.y<<endl;
    tot=0;
    int a,b;
    for(int i = 1;i<=n;i++)
    {
      cin>>a>>b;
      if(a<st.x||a>en.x||b>max(st.y,en.y)||b<min(st.y,en.y))
        continue;
      node[tot].x=a;
      node[tot++].y=b;
    }
    //cout<<tot<<endl;
    if(st.y<=en.y)
    {
      sort(node,node+tot,cmp1);
      for(int i=0;i<tot;i++)
      {
        all[i]=node[i].y;
      }
      cout << LIS(less_equal<int>()) << endl;
    }
    else
    {
      sort(node,node+tot,cmp2);
      for(int i=0;i<tot;i++)
      {
        all[i]=node[i].y;
      }
      cout << LIS(greater_equal<int>()) << endl;
    }

  }
  return 0;
}
