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
int m;
int shu[1000];
int main()
{
  int n;
  while(cin>>n>>m)
  {
    for(int i= 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    int ans = 0;
    for(int i = 0;i<1e4-1;i++)
    {
      ll op = 0;
      int flag = 1;
      ll k = i;
      for(int j = 1;j<=4;j++)
      {
        if(k%10 >=m) flag = 0;
        op += (k%10)*shu[j];
        k/=10;
      }
      if(op%m == 0 && flag)
      {cout<<i<<endl;
      ans++;}
    }
    cout<<ans<<endl;
  }
  return 0;
}
