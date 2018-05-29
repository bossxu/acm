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
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
const int maxn =  1e6+5;
int bit[maxn];
int shu[maxn];
int n;
int sum(int i)
{
  int s = 0;
  while(i>0)
  {
    s+=bit[i];
    i-=(i&-i);
  }
  return s;
}
void add(int i,int x)
{
  while(i<=n)
  {
    bit[i]+=x;
    i+= (i&-i);
  }

}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  while(cin>>n)
  {
    for(int i = 0;i<n;i++)
    {
      cin>>shu[i];
    }
    clr(bit,0);
    ll ans = 0;
    for(int i = 0;i<n;i++)
    {
      ans+=i-sum(shu[i]);
      add(shu[i],1);
    }
    ans = 7*n+1-ans;
    if(ans%2 == 0) cout<<"Um_nik"<<endl;
    else cout<<"Petr"<<endl;
  }
  return 0;
}
