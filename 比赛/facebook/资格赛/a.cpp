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
char s[100][100];
int vis[55];
int main()
{
  int t;
  // freopen("tourist.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  int n,k;
  ll st;
  int cnt = 1;
  while(t--)
  {
    cin>>n>>k>>st;
    for(int i = 1;i<=n;i++)
    {
      cin>>s[i];
    }
    st = ((st-1)%n)*(k)%n;
    st+=1;
    cout<<"Case #"<<(cnt++)<<":";
    clr(vis,0);
    for(int i = 0;i<k;i++)
    {
      int tot = (st+i)%n;
      if(tot == 0) tot = n;
      vis[tot] = 1;
    }
    for(int i = 1;i<=n;i++)
    {
      if(vis[i]) cout<<" "<<s[i];
    }
    cout<<endl;
  }

  return 0;
}
