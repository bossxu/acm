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


int main()
{
  int t;
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  cin>>t;
  while(t--)
  {
      ll M,N;
      scanf("%lld%lld",&M,&N);
      //cout<<N<<endl;
      ll ans=0;
      for(int i=1;i<=M;i++)
      {
          int a,b;
          scanf("%d%d",&a,&b);
          ll k=N/(a+b);
          ll p=N%(a+b);
          //cout<<k*a+max(0LL,p-b)<<endl;
          ans+=k*a+max(0LL,p-b);
      }
      //cout<<ans<<endl;
      printf("%lld\n",(ans+N-1)/N);
  }
  return 0;
}
