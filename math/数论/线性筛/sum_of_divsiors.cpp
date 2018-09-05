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
const int N=1e6;
int num[N+5];
int ans[N+5];
int prim[N+6];
int cnt;
void initial()
{
    cnt=1;
    ans[1] = 1;
    for (int i=2 ; i<N ; ++i)
    {
      if(!ans[i])
      {
        ans[i] = 2;
        num[i] = 1;
        prim[cnt++] = i;
      }
        for(int j = 1;j<cnt && i*prim[j] < N;j++)
        {
          if(i%prim[j])
          {
            num[i*prim[j]] = 1;
            ans[i*prim[j]] = ans[i]*2;
          }
          else
          {
             num[i*prim[j]] = num[prim[j]]+1;
             ans[i*prim[j]] = ans[i]/(num[i]+1)*(num[i*prim[j]]+1);
          }
        }
      }
}

int main()
{
  int n;
  initial();
  while(cin>>n)
  {
    cout<<ans[n]<<endl;
  }
  return 0;
}
