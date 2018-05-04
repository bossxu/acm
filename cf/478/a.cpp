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
#define mod 1e9+7
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int shu[27];
set<ll>q;
char s[1005];
int main()
{
  //freopen("in.txt","r",stdin);
  int n;
  while(cin>>n)
  {
    q.clear();
    for(int i = 1;i<=n;i++)
    {
      scanf("%s",s);
      clr(shu,0);
      for(int i = 0;i<strlen(s);i++)
      {
        shu[s[i]-'a'] = 1;
      }
      ll ans = 0;
      for(int i = 0;i<27;i++)
      {
        ans+=shu[i];
        ans*=2;
      }
      q.insert(ans);
    }
    cout<<q.size()<<endl;
  }
  return 0;
}
