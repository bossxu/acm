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

int shu[1005];

int main()
{
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    sort(shu+1,shu+n+1);
    int ans = -1;
    for(int i = n;i>=3;i--)
    {
      if(shu[i-2]+shu[i-1] > shu[i])
      {
        ans = shu[i-2]+shu[i-1]+shu[i];
        break;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
