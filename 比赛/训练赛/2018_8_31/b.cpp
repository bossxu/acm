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
int shu[30];
int csl[20][30];
int val[30];
int main()
{
  ios_close;
  int n;
  int m;
  while(cin>>n)
  {
    int a;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    cin>>m;
    for(int i = 0;i<m;i++)
    {
      for(int j = 1;j<=n;j++)
      {
        cin>>csl[i][j];
      }
    }
    int st = 0;
    vector<int>q;
    q.clear();
    for(int i = 0;i<(1<<m);i++)
    {
      clr(val,0);
      int now = 0;
      for(int j = 0;j<m;j++)
      {
        if((1<<j)&i)
        {
          now ++;
          for(int k = 1;k<=n;k++)
          {
            val[k] += csl[j][k];
          }
        }
      }
      int flag = 1;
      for(int k = 1;k<=n;k++)
      {
        if(val[k]<shu[k])
        {
          flag = 0;
        }
      }
      if(flag)
      {
        if(now>st)
        {
          st = now;
          q.clear();
          for(int k = 0;k<m;k++)
          {
            if(i&(1<<k))
            {
              q.pb(k);
            }
          }
        }
      }
    }
    cout<<q.size();
    for(int i = 0;i<q.size();i++)
    {
      cout<<" "<<q[i]+1;
    }
    cout<<endl;
  }
  return 0;
}
