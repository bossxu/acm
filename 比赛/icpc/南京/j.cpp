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
const int maxn = 20000001;
const int N=2e7+5;
bool mark[N];
ll prim[N],d[N],num[N];
int cnt;
void initial()
{
    cnt=0;
    d[1]=1;
    for (int i=2 ; i<N ; ++i)
    {
        if (!mark[i])
        {
            prim[cnt++]=i;
            num[i]=1;
            d[i]=2;
        }
        for (int j=0 ; j<cnt && i*prim[j]<N ; ++j)
        {
            mark[i*prim[j]]=1;
            if (!(i%prim[j]))
            {
                num[i*prim[j]]=num[i]+1;
                if(num[i*prim[j]] > 2)
                d[i*prim[j]] = 0;
                if(num[i*prim[j]] == 2)
                d[i*prim[j]]=d[i]/2;
                break;
            }
            d[i*prim[j]]=d[i]*d[prim[j]];
            num[i*prim[j]]=1;
        }
    }
    for(int i = 1;i<=maxn;i++)
    {
      d[i] += d[i-1];
    }
}

int main()
{
  int t;
  initial();
  scanf("%d",&t);
  while(t--)
  {
    ll n;
    scanf("%lld",&n);
    printf("%lld\n",d[n]);
  }
  return 0;
}
