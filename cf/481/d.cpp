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
#define clr(a,x) memset(a,x,sizeof(a))
ll shu[100005];
int n;
int check(ll cha)
{
  int ko = 1;
  for(int i = 3;i<=n;i++)
  {
    ll quan = shu[i]-shu[1];
    ll kai = cha * (i-1);
    ll l = abs(quan-kai);
    if(l == 1) ko++;
    if(l>1)
     return 0;
  }
  //cout<<ko<<endl;
  return ko;
}
int main()
{
  std::ios::sync_with_stdio(false);
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    int flag = 0;
    int cha = INF;
    for(int i = -1;i<=1;i++)
    {
      for(int j = -1;j<=1;j++)
      {
        shu[1]+=j;shu[2]+=i;
        int ans = check(shu[2]-shu[1]);
        if(ans>0)
        {
          flag = 1;
          if(i!=0) ans++;
          if(j!=0) ans++;
          cha = min(ans-1,cha);
        }
        shu[2]-=i;shu[1]-=j;
      }
    }
    if(!flag) cout<<-1<<endl;
    else
    {
      cout<<cha<<endl;
    }
  }
  return 0;
}
