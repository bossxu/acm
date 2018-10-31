//langman
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
ll shu[100005];
int main()
{
  ios_close;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  int n,t;
  while(cin >> n >> t)
  {
    for(int i = 1;i<=n;i++)
    {
      cin >> shu[i];
    }
    int prest,ti;
    prest = t/shu[1];
    cout<<prest+1<<endl;

    ll maxn = shu[1];
    ll st = shu[1];
    for(int i = 2;i<=n;i++)
    {
      st += shu[i];
      if(t < st)
      {
        cout <<1<<endl;
        continue;
      }
      if(shu[i] >= maxn)
      {
        maxn = shu[i];
        prest = (t-st)/shu[i];
      }
      else
      {
        prest = (t-st)/maxn;
      }
      cout << prest+2 << endl;
    }
  }
  return 0;
}
