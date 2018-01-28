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
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const int maxn=300005;
const double eps = 1e-6;
struct st{
  int a,index;
  friend bool operator < (st c, st b)
    {
        if(c.a == b.a)
         return c.index<b.index;
        return c.a < b.a;
    }
};
st node[maxn];
int shu[maxn];
int main()
{
   int n,k;
   while(cin>>n>>k)
   {
     priority_queue<st>q;
     priority_queue<st>Q;
     for(int i=1;i<=n;i++)
     {
       st p;
       scanf("%d",&p.a);
       p.index=i;
       q.push(p);
     }
     int sum=0;
     for(int i=1;i<=n;i++)
     {
        st p;
        if(!Q.empty())
        {
          p=Q.top();
          Q.pop();
        }
        else
        {
          p=q.top();
          q.pop();
        }
          if(p.index>i+k)
        {
          while(!Q.empty() && p.index>i+k)
          {
            q.push(p);
            p=Q.top();
            Q.pop();
          }
          while(p.index>i+k)
          {
            Q.push(p);
            p=q.top();
            q.pop();
          } 
        }
        sum+=p.a*(i+k-p.index);
        //printf("---%d %d\n",p.a,p.index);
        shu[p.index]=i+k;
     }
     printf("%d\n",sum);
     for(int i=1;i<n;i++)
     {
       printf("%d ",shu[i]);
     }
     printf("%d\n",shu[n]);
   }

  return 0;
}
