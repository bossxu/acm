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

int shu[205][205];
int main()
{
  int t;
  ios_close;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    int a = n&1,b = m&1;
    if(b && a)
    {
      for(int i = 1;i<=n;i++)
      {
        for(int j = 1;j<=m;j++)
        {
          shu[i][j] = 1;
        }
      }
    }
    if(b && !a)
    {
      for(int i = 1;i<=n;i++)
      {
        for(int j = 1;j<=m;j++)
        {
          shu[i][j] = i%2;
        }
      }
    }
    if(!b && a)
    {
      for(int i = 1;i<=n;i++)
      {
        for(int j = 1;j<=m;j++)
        {
          shu[i][j] = j%2;
        }
      }
    }
    if(!b && !a)
    {
      if(max(n,m)+min(n,m)/2-1 > n+m-4){
      if(n>=m)
      {
        for(int i = 1;i<=n;i++)
        {
          for(int j = 1;j<=m;j++)
          {
            if(i % 2 == 1)
            {
              if(j == 1) shu[i][j] = 1;
              else if(j ==m) shu[i][j] = 0;
              else shu[i][j] = (j+1)%2;
            }
            else
            shu[i][j] = j%2;
          }
        }
      }
      else
      {
        for(int j = 1;j<=m;j++)
        {
          for(int i = 1;i<=n;i++)
          {
            if(j % 2 == 1)
            {
              if(i == 1) shu[i][j] = 1;
              else if(i ==n) shu[i][j] = 0;
              else shu[i][j] = (i+1)%2;
            }
            else
            shu[i][j] = i%2;
          }
        }
      }
    }
    else
    {
        for(int i = 1;i<=m;i++)
        {
          shu[1][i] = 1;
          shu[n][i] = 0;
        }
        for(int i = 2;i<n;i++)
        {
          for(int j = 1;j<=m;j++)
          {
            if(i % 2 == 1)
            {
              if(j == 1) shu[i][j] = 1;
              else if(j ==m) shu[i][j] = 0;
              else shu[i][j] = (j+1)%2;
            }
            else
            shu[i][j] = j%2;
          }
        }
    }
    }
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        if(shu[i][j]) cout<<"(";
        else cout<<")";
      }
      cout<<endl;
    }
  }
  return 0;
}
