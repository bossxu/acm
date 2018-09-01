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
const int N=2e7+5;
bool mark[N];
int prim[N],d[N],num[N];
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
                d[i*prim[j]]=d[i]/(num[i]+1)*(num[i*prim[j]]+1);
                break;
            }
            d[i*prim[j]]=d[i]*d[prim[j]];
            num[i*prim[j]]=1;
        }
    }
}
int main()
{
  int n;
//  ll ans = 0;
  initial();
  while(cin>>n)
  {
    cout<<d[n]<<endl;
  }
  return 0;
}
