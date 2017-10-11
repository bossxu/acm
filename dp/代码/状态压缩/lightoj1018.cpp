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
struct point
{
  int x,y;
}node[17];
int line[26][26];
int n;
int dp[1<<20];
void init()
{
  clr(dp,0);
  clr(line,0);
  dp[0] = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      line[i][j] = (1<<i) | (1<<j);
      int dx = node[i].x - node[j].x,dy = node[i].y-node[j].y;
      for(int k = j+1;k<n;k++)
      {
        int dx2 = node[k].x-node[i].x,dy2 = node[k].y-node[i].y;
        if(dx2 * dy == dy2 * dx)
           line[i][j] |= (1<<k);
      }
      line[j][i] = line[i][j];
    }
  }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
      cin>>n;
      for(int i = 0;i<n;i++)
      {
        cin>>node[i].x>>node[i].y;
      }

    }
    return 0;
}
