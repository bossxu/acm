#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;
int shu[200005];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    int num = sqrt(n);
    int tot = 1;
    for(int i = 1;;i++)
    {
      for(int j = min(num*i,n);j>num*(i-1);j--)
      {
        shu[tot++] = j;
      }
      if(i*num >= n)
      break;
    }
    for(int i = 1;i<=n;i++)
    {
      cout<<shu[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
