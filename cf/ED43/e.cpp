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
struct Node
{
  int hea,hur;
}node[200005];
int cmp(Node a, Node b)
{
  return a.hea-a.hur > b.hea-b.hur;
}
int main()
{
   int n,a,b;
   while(cin>>n>>a>>b)
   {
     ll ans = 0;
     for(int i = 1;i<=n;i++)
     {
       scanf("%d%d",&node[i].hea,&node[i].hur);
       ans+=node[i].hur;
     }
     sort(node+1,node+1+n,cmp);
     int maxn = 0;
     for(int i = 1;i<=min(b,n);i++)
     {
       maxn = max(maxn,node[i].hea);
       if(node[i].hea-node[i].hur <=0) break;
       ans+=node[i].hea-node[i].hur;
     }
     ans+=maxn*(pow(2,a)-1);
     cout<<ans<<endl;
   }
  return 0;
}
