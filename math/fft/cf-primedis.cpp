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
vector<int>map[500005];
bool vis[500005];
int main()
{
  int n;
  while(cin>>n)
  {
    int a,b;
    for(int i = 1;i<n;i++)
    {
      scanf("%d%d",&a,&b);
      map[a].push_back(b);
      map[b].push_back(a);
    }
  }
  return 0;
}
