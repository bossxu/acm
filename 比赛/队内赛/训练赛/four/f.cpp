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
char s[300005];
vector<int>in[300005];
vector<int>out[300005];
queue<int>q;
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  int m;
  while(cin>>n>>m)
  {
    cin>>s;
    while(q.empty()) q.pop();
    for(int i = 0;i<=n;i++)
    {
        in[i].clear();
        out[i].clear();
        in[i].push_back(0);
    }
    for(int i = 1;i<=m;i++)
    {
      int a,b;
      cin>>a>>b;
      out[b].push_back(a);
    }
  }
  return 0;
}
