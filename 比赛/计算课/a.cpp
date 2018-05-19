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
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int shu[20005];
int n;
int check(int l)
{
  ll ko = 0;
  for(int i = 1;i<=n;i++)
  {
    if(shu[i]>l) ko+=shu[i]-l;
  }
  return ko;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  while(cin>>n)
  {
    int right = 20000;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    ll p,s;
    cin>>p>>s;
    int left = 1;
    int mid;
    ll ui = s/p;
    while(left <right)
    {
      //cout<<left<<" "<<right<<endl;
       mid = (left+right)/2;
      if(check(mid) <= ui)
      {
        right = mid;
      }
      else
      {
        left = mid+1;
      }
    }
    cout<<right<<endl;
  }
  return 0;
}
