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
int map[505][505];
struct Node
{
  int x,y;
  int st;
  string s;
}node[100005];
int cmp(Node a, Node b)
{
  return a.s<b.s;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n,m,k;
  while(cin>>n>>m>>k)
  {
    for(int i = 1;i<=k;i++)
    {
      cin>>node[i].x>>node[i].y>>node[i].st;
      cin>>node[i].s;
    }
    sort(node+1,node+k+1,cmp);
    int num = 0;
    int item = 0;
    int maxn = 0;
    clr(map,0);
    for(int i = 1;i<=k;i++)
    {
      if(node[i].st == 0)
      {
         int a = node[i].x , b = node[i].y;
         map[a][b]++;
         if(map[a][b] == 1) num++;
      }
      if(node[i].st == 1)
      {
        int a = node[i].x , b = node[i].y;
        if(map[a][b] == 1)
        {
          num--;
        }
        map[a][b]--;
      }
      if(maxn<=num)
      {
        maxn = num;
        item = i;
      }
    }
      clr(map,0);

      for(int i = 1;i<=item;i++)
      {
        if(node[i].st == 0)
        {
           int a = node[i].x , b = node[i].y;
           map[a][b]++;
        }
        if(node[i].st == 1)
        {
          int a = node[i].x , b = node[i].y;
            map[a][b]--;
        }
      }
      for(int i = 1;i<=n;i++)
      {
        for(int j = 1;j<=m;j++)
        {
          if(map[i][j]) cout<<1;
          else cout<<0;
        }
        cout<<endl;
      }

    }

  return 0;
}
