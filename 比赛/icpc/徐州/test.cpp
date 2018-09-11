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
int num;
int all;
int n;
int ans[100];
void dfs(int st,int m)
{
  if(st >= n)
  {
    int flag = 0;
    for(int i = 0;i<n;i++)
    {
      if(ans[i]+ans[(i+1)%n] == 3 )
      flag++;
    }
    if(flag == 1 && ans[0]+ans[n-1] == 4) {all++;}
    if(!flag)
    {
      num++;
      for(int i = 0;i<n;i++)
      {
        cout<<ans[i];
      }
      cout<<endl;
    }
    return;
  }
  for(int i = 0;i<(1<<m);i++)
  {
    ans[st] = i;
    dfs(st+1,m);
  }
  return;
}

int main()
{
  int m;
  while(cin>>n>>m)
  {
    num = 0;
    all = 0;
    dfs(0,m);
    cout<<num<<endl;
    cout<<all<<endl;
    //cout<<all<<endl;
  }
  return 0;
}
