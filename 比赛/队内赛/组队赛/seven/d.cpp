#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e5+100;
ll b[maxn];
ll sum[maxn];
const ll mod=1e9+7;
ll quickmod(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;char s[maxn];
   while(scanf("%d",&n)==1)
   {
       scanf("%s",s);
       int len=strlen(s);
       mem(b,0);
       mem(sum,0);
       ll x=0;
       ll ans=1;
       for(int i=len-1;i>=0;i--)
       {
           if(s[i]=='1') b[len-i-1]=1;
       }
       for(int i=n-1;i>=0;i--)
       {
           sum[i]=sum[i+1]+(b[i]==1?0:1);
           //cout<<sum[i]<<endl;
       }
       //cout<<sum[0]<<endl;
       for(int i=0;i<n;i++)
       {
           if(b[i]){
             ans=(ans*(quickmod(2,sum[i])-1+mod)%mod)%mod;
              x+=sum[i];
              //cout<<x<<endl;
           }
       }
       x+=sum[0]*(sum[0]-1)/2;
      // cout<<x<<endl;
       x=1LL*n*(n-1)/2-x;
       x%=(mod-1);
       //x%=mod;
       //cout<<ans<<endl;
       //cout<<x<<endl;
       ans=(ans*quickmod(2,x)+mod)%mod;
      printf("%lld\n",ans);
      // cout<<ans<<endl;
   }

 return 0;
  }
