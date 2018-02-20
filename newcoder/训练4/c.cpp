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
const int maxn = 1000005;
ll a[maxn],b[maxn],p[maxn];
int main()
{
   int n,m;
   while(cin>>n>>m)
   {
     for(int i = 1;i<=n;i++)
     scanf("%lld",&a[i]);
     for(int i = 1;i<=m;i++)
     scanf("%lld",&b[i]);
     int flag = 1,l =1,r =1;
     sort(a+1,a+n+1);
     sort(b+1,b+m+1);
     while(l<= n || r<=m)
     {
       //cout<<"l-r"<<l<<"->"<<r<<endl;
       if(a[l] == b[r])
       {
         //cout<<"yes"<<endl;
         p[flag++] = a[l];
         l++,r++;
       }
        else if(a[l]>b[r])
       {
         r++;
         if(r>m) break;
       }
       else if(a[l] < b[r])
       {
        //cout<<"yes"<<endl;
         l++;
         if(l>n) break;
       }
     }
     //cout<<flag<<endl;
     if(flag == 1) cout<<"empty"<<endl;
     else
     {
       for(int i = 1;i<flag-1;i++)
       {
         cout<<p[i]<<" ";
       }
       cout<<p[flag-1]<<endl;
     }
   }
  return 0;
}
