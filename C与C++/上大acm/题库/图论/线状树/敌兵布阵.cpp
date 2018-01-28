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
#include<map>
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
int di[50005],t[50005];
int n;
//树状数组 
int lowbit(int x)
{
    return x&(-x);
}
void a_change(int x,int p)//将第x个数加p 
{
    while(x<=n)
    {
        t[x]+=p;
        x+=lowbit(x);
    }
    return;
}
void e_change(int x,int p)//将第x个数加p 
{
    while(x<=n)
    {
        t[x]-=p;
        x+=lowbit(x);
    }
    return;
}
int sum(int k)//前k个数的和 
{
    int ans=0;
    while(k>0)
    {
        ans+=t[k];
        k-=lowbit(k);
    }
    return ans;
}
int ask(int l,int r)//求l-r区间和 
{
    return sum(r)-sum(l-1); 
}
int main()
{
    int l;
    cin>>l;
    int c=0;
    while(l--)
    {      
           cin>>n;
           clr(t,0);
           char cao[7];
           for(int i=1;i<=n;i++)
           {
               cin>>di[i];
               a_change(i,di[i]);
           }
           printf("Case %d:\n",++c);
           while(scanf("%s",cao)!=EOF && cao[0]!='E')
           {
             int x,y;
             cin>>x>>y;
             if(cao[0]=='A')
             {
               a_change(x,y);
               continue;
             }
             if(cao[0]=='S')
             {
                 e_change(x,y);
                 continue;
             }
             if(cao[0]=='Q')
             {
                 int k= ask(x,y);
                 printf("%d\n",k);
                 continue;
             }
            }
       
    }
    return 0;
}