#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef unsigned long long ll;
#define INF 0x3f3f3f3f
#define mod 1e9+7
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
const int MAXN = 65;
const int MAX = 1000005;
ll x[MAXN];
int flag = 0;
ll su[MAX],cnt;
bool isprime[MAX];
void prime()
{
    cnt=1;
    memset(isprime,1,sizeof(isprime));//初始化认为所有数都为素数
    isprime[0]=isprime[1]=0;//0和1不是素数
    for(long long i=2;i<=MAX;i++)
    {
        if(isprime[i])
            su[cnt++]=i;//保存素数i
        for(long long j=1;j<cnt&&su[j]*i<MAX;j++)
        {
            isprime[su[j]*i]=0;//筛掉小于等于i的素数和i的积构成的合数
        }
    }
}
ll multi(ll a, ll b, ll p) {
    ll ans = 0;
    while(b) {
        if(b&1LL) ans = (ans+a)%p;
        a = (a+a)%p;
        b >>= 1;
    }
    return ans;
}
ll qpow(ll a, ll b, ll p) {
    ll ans = 1;
    while(b) {
        if(b&1LL) ans = multi(ans, a, p);
        a = multi(a, a, p);
        b >>= 1;
    }
    return ans;
}
bool Miller_Rabin(ll n) {
    if(n == 2) return true;
    int s = 5, i, t = 0; //s是随机函数
    ll u = n-1;
    while(!(u & 1)) {
        t++;
        u >>= 1;
    }
    while(s--) {
        ll a = rand()%(n-2)+2;
        x[0] = qpow(a, u, n);
        for(i = 1; i <= t; i++) {
            x[i] = multi(x[i-1], x[i-1], n);
            if(x[i] == 1 && x[i-1] != 1 && x[i-1] != n-1) return false;
        }
        if(x[t] != 1) return false;
    }
    return true;
}
int main()
{
  //freopen("in.txt","r",stdin);
   int t;
   cin>>t;
   ll n;
   prime();
   while(t--)
   {
     scanf("%lld",&n);
     if(n == 4)
     {
       cout<<"2 2"<<endl;
       continue;
     }
     for(ll i = 1;i<cnt;i++)
     {
       if(Miller_Rabin(n-su[i]))
       {
         cout<<su[i]<<" "<<n-su[i]<<endl;
         break;
       }
     }
   }

  return 0;
}
