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
int pre[105];
struct Node
{
  int x,y;
}node[105];
int find(int st)
{
  //cout<<st<<endl;
  if(st == pre[st])
   return st;

   return find(pre[st]);
}
void init()
{
  for(int i = 1;i<=100;i++)
  {
    pre[i] = i;
  }
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n)
  {
    init();
    for(int i = 1;i<=n;i++)
    {
      cin>>node[i].x>>node[i].y;
    }
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=n;j++)
      {
        if(i == j) continue;
        if(node[i].x == node[j].x || node[i].y == node[j].y)
        {
          pre[find(j)] = find(i);
        }
      }
    }
    //cout<<"hello"<<endl;
    set<int>q;
    for(int i = 1;i<=n;i++)
    {
      q.insert(find(i));
    }
    cout<<q.size()-1<<endl;
  }
  return 0;
}
