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
const int MAX = 1040;
int data[MAX][MAX],n;
int dp[MAX][MAX];
int lowbit(int x) {
    return x&-x;
}
void Add(int x, int y, int w) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= n; j += lowbit(j)) {
            data[i][j] += w;
        }
    }
}
int Sum(int x, int y) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j -= lowbit(j)) {
            ans += data[i][j];
        }
    }
    return ans;
}
void init()
{
  for(int i = 1;i<=1024;i++)
  {
    for(int j = 1;j<=1024;j++)
    {
      if((i+j)%2)
      {
        Add(i,j,1);
      }
      dp[i][j] =(i+j)%2;
    }
  }
}
int main()
{
  int t;
  n = 1024;
  char op[5];
  int x1,y1,x2,y2;
  int ans = 0;
  while(scanf("%d",&t) == 1)
  {
    init();
    for(int i = 1;i<=t;i++)
    {
      scanf("%s",op);
      if(op[0] == 'R')
      {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        ans = Sum(x2,y2)-Sum(x2,y1-1)-Sum(x1-1,y2)+Sum(x1-1,y1-1);
        printf("%d %d\n",(y2-y1+1)*(x2-x1+1)-ans,ans);
      }
      if(op[0] == 'A')
      {
        scanf("%d%d",&x1,&y1);
        if(dp[x1][y1] == 1)
        {
          Add(x1,y1,-1);
          dp[x1][y1] = 0;
        }
      }
      if(op[0] == 'B')
      {
        scanf("%d%d",&x1,&y1);
        if(dp[x1][y1] == 0)
        {
          Add(x1,y1,1);
          dp[x1][y1] = 1;
        }
      }
    }
  }
  return 0;
}
