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
  int l,r;
  int index;
}node[300005];
int cmp(Node a,Node b)
{
  return a.l<b.l;
}
int main()
{
   int n;
   while(cin>>n)
   {
     for(int i = 1;i<=n;i++)
     {
       scanf("%d %d",&node[i].l,&node[i].r);
       node[i].index = i;
     }
     sort(node+1,node+n+1,cmp);
     int flag = 0,maxr = node[1].r;
     int le = 1,re;
     for(int i = 2;i<=n;i++)
     {
       if(node[i].r<=maxr)
       {
         re = i;
         flag = 1;
         break;
       }
       else
       {
         maxr = node[i].r;
         le = i;
       }
     }
     if(flag)
     {
       cout<<node[re].index<<" "<<node[le].index<<endl;
     }
     else
     cout<<"-1 -1"<<endl;
   }

  return 0;
}
