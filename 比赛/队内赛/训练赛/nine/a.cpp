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
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n,p;
  int m,o;
  while(cin>>n>>p){
    ll a = 0,b = 0;
  int k;
  for(int i = 1;i<=n;i++)
  {
    cin>>k;
    a = a*p+k;
  }
  cin>>m>>o;
  for(int i = 1;i<=m;i++)
  {
    cin>>k;
    b = b*o+k;
  }
  if(a == b) cout<<"="<<endl;
  if(a<b) cout<<"<"<<endl;
  if(a>b) cout<<">"<<endl;
}
  return 0;
}
