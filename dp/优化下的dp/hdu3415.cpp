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
const int N = 1e5+5;
vector<int>q;
ll sum[N*2];
int main()
{
  ios_close;
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    q.clear();
    int a;
    for(int i = 1;i<=n;i++)
    {
      cin>>a;
      q.pb(a);
    }
    for(int i = 0;i<n;i++)
    {
      q.pb(q[i]);
    }
    sum[0] = q[0];
    for(int i = 1;i<2*n;i++)
    {
      sum[i] = sum[i-1] +q[i];
    }

  }
  return 0;
}
