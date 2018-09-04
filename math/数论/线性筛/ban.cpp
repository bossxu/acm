#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
const int N=1e5+5;
bool mark[N];
int prim[N];
int cnt;
void initial()
{
    cnt=0;
    for (int i=2 ; i<N ; ++i)
    {
        if (!mark[i])
            prim[cnt++]=i;
        for (int j=0 ; j<cnt && i*prim[j]<N ; ++j)
        {
            mark[i*prim[j]]=1;
            if (!(i%prim[j]))
                break;
        }
    }
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  initial();
  while(cin>>n)
  {
    cout<<prim[n]<<" ";
  }
  return 0;
}
