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
int a[1000006];
int shu[1000006];
int s[1000006];
int z;
void getg( int n)//初始化公因数
{
    z=0;int i,c=n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0) {shu[z++]=i;while(n%i==0) n/=i;}
    }
   if(n>1) shu[z++]=n;
}
void init(int n)
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; i*j <= n; ++j)
            s[i] += a[i*j];
    }
}
void update(int index, int tval)
{
    int m = sqrt(index);
    for(int i = 1; i <= m; ++i)
    {
        if(index%i == 0)
        {
            if(i*i == index)
                s[i] = s[i]-a[index] + tval;
            else
            {
               s[index/i] = s[index/i] - a[index] + tval;
                s[i] =s[i] - a[index] + tval;
            }
        }
    }
    a[index] = tval;
}
ll solve(int num)  //好东西
{  
    ll i,j;  
    ll ans=0,tem,flag;  
    getg(num);
    for(i=1;i<1<<z;i++)  
    {  
        tem=1,flag=0;  
        for(j=0;j<z;j++)  
            if(i&(ll)1<<j)  
                {flag++;tem=tem*shu[j];}  
        if(flag&1) 
           ans+=s[tem] ;  
        else 
           ans-=s[tem] ;
    }  
    return ans;  
}
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)==2)
    {
        memset(s,0,sizeof(s));
        ll sum=0;
        for(int i=1;i<=n;i++)
         {
             cin>>a[i];
             sum+=a[i];
         }
         init(n);
        for(int i=0;i<q;i++)
        {
            int t;
            cin>>t;
            if(t==2)
            {
               int k,l;
               ll p=sum;
               cin>>k;
               p-=solve(k);
               printf("%lld\n",p);
            }
            if(t==1)
            {
                int b,l;
                cin>>b>>l;
                sum=sum+l-a[b];
               update(b,l);
            }
        }
    }
    return 0;
}