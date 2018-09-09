#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=5e4+100;
struct node
{
  int x,y;
}a[maxn];
int main(){
  /*#ifndef ONLINE_JUDGE
     freopen("data.in","r",stdin);
      freopen("data.out","w",stdout);
     #endif*/
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(scanf("%d",&n)==1)
  {
    for(int i=1;i<=n;i++)
    {
      scanf("%d%d",&a[i].x,&a[i].y);//,v.pb(a[i].x);
    }
    ll ans=0;
    node mx;mx.x=0;mx.y=0;
    node my;my.x=0;my.y=0;
    for(int i=n;i>=1;i--)
    {
      if(a[i].x>mx.x)
      {
        ans+=a[i].x-mx.x+a[i].y;
        mx.x=a[i].x;
       if(a[i].y>my.y) my.y=a[i].y;
      }
      else
      {
        ans+=a[i].y-my.y+a[i].x;
        my.y=a[i].y;
      }
    //  cout<<ans<<endl;
    }
    printf("%lld\n",ans);


  }
 return 0;
  }
