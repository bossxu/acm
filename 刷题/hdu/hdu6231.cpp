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
int n,k;
ll m;
// 二分加尺取
//比赛的时候我没有想到这样的做法，很流弊

ll a[100005];
ll b[100005];
bool check(ll st)
{
  ll ans = 0;
  int num = 0; //ans表示的是st一定不是当前区间第k大的区间个数，用尺取法去处理
  int l,r;
  l = 1;r = 0;
  while(r <= n)
  {
    if(num<k)
    {
      if(a[r+1] >= st) num++;
      r++;
    }
    else
    {
      if(num == k) ans += (n-r)+1;
      if(a[l] >= st) num--;
      l++;
      if(ans >= m) return true;
    }
  }
  //cout<<st<<" "<<ans<<endl;
  return false;
}
int main()
{
  ios_close;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  int t;cin>>t;
  while(t--)
  {
    cin >> n >> k >> m;
    for(int i = 1;i <= n;i++)
    {
      cin>>a[i];
      b[i] = a[i];
    }
    sort(b+1,b+n+1);
    int l = 1,r = n,mid;
    ll ans = -1;
    while(l<=r)
    {
      mid = (l+r)>>1;
      if(check(b[mid]))
      {
        ans = b[mid];
        l = mid + 1;
      }
      else
      r = mid - 1;
    }
    cout<<ans<<endl;
  }
  return 0;
}
