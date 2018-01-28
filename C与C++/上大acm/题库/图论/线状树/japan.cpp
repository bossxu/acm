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
const double eps = 1e-6;
// 知识点分解：树状数组
const int maxn = 1005;  
struct node{
    int i,j;
}N[1000005];
int a[maxn],b[maxn];
int lowbit(int x)
{
    return x&(-x);
}
void change(int x,int p ,int *t,int n )//将第x个数加p 
{
    while(x<=n)
    {
        t[x]+=p;
        x+=lowbit(x);
    }
    return;
}
int sum(int k,int *t)//前k个数的和 
{
    int ans=0;
    while(k>0)
    {
        ans+=t[k];
        k-=lowbit(k);
    }
    return ans;
}
int cmp(node a,node b)
{
    if(a.i==b.i) return a.j<b.j;
    return a.i<b.i;
}
int main()
{
    
    int t;
    cin>>t;
    int co=0;
    while(t--)
    {
      int m,n,k;
      scanf("%d%d%d",&m,&n,&k);
      for(int i=1;i<=k;i++)
      {
          scanf("%d%d",&N[i].i,&N[i].j);
      }
      sort(N+1,N+k+1,cmp);
      clr(a,0);
      clr(b,0);
      ll s= 0 ;
      for(int i=1;i<=k;i++)
      {
         
         change(N[i].i,1,a,m);
         change(N[i].j,1,b,n);
         ll l= sum(N[i].i,a)-sum(N[i].j,b);
         l=l<0?-l:l;
         s+=l;
      } 
      printf("Test case %d: %lld\n",++co,s);
    }
    return 0;
}