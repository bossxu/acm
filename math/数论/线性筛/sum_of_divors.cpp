#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
const int N = 1e6+5;
int prime[N];
int num[N];
int d[N];
int cnt;
void init()
{
  clr(d,0);clr(num,0);cnt = 0;
  for(int i = 2;i<=N;i++)
  {
    if(!d[i])
    {
      prime[cnt++] = i;
      d[i] = 2;
      num[i] = 1;
    }
    for(int j = 0;j<cnt && i*prime[j] < N;j++)
    {
      if(i%prime[j])
      {
        num[i*prime[j]] = 1;
        d[i*prime[j]] = d[i]*2;
      }
      else
      {
        num[i*prime[j]] = num[i]+1;
        d[i*prime[j]] = d[i]/(num[i]+1)*(num[i*prime[j]]+1);
      }
    }
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  int n;
  while(cin>>n)
  {
    cout<<d[n]<<endl;
  }
  return 0;
}
