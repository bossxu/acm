#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
vector<int>q[400005];
int cur;
int n,d,k;
void dfs()
{
  queue<int>op;
  op.push(cur);
  while(!op.empty())
  {
    int it = op.front();
    op.pop();
    for(int i = 1;i<=k-1;i++)
    {
      cur++;
      if(cur>n) return;
      q[it].push_back(cur);
      op.push(cur);
    }
    if(it == 1)
    {
      cur++;
      if(cur>n) return;
      q[it].push_back(cur);
      op.push(cur);
    }
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  while(cin>>n>>d>>k)
  {
    for(int i = 1;i<=n;i++)
    {
      q[i].clear();
    }
    int i = 1;
    int tot = 1;
    ll sum = 1;
    int flag = 0;
    for(int i = 1;i<=d/2;i++)
    {
      if(tot == 1)
      {
        sum+=tot*k;
        tot = k;
      }
      else
      {
        sum+=tot*(k-1);
        tot = tot*(k-1);
      }
      if(sum>=n)
      {
        flag = 1;
        break;
      }
    }
    //cout<<sum<<endl;
    if(!flag)
    {
      if(d%2)
      {
        sum+=k-1;
        if(sum>=n)
        {
          flag = 1;
        }
        else
        cout<<"NO"<<endl;
      }
      else
      cout<<"NO"<<endl;
    }
    if(flag)
    {
      cout<<"YES"<<endl;
      cur = 1;
      dfs();
      for(int i = 1;i<=n;i++)
      {
        for(int j = 0;j<q[i].size();j++)
        {
          cout<<i<<" "<<q[i][j]<<endl;
        }
      }
    }
  }
  return 0;
}
