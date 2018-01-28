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
const double eps = 1e-6;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int n;
   int a[100];
   while(cin>>n)
   {
     if(n==0) {cout<<"*"<<endl;break;}
     int ans = 0;
     clr(a,0);
     for(int i =1;i<=n;i++)
     {
       int k,c,b;
       scanf("%d%d%d",&k,&b,&c);
       for(int j =b;j>c;j--)
       {
         a[j]+=k;
         ans = max(a[j],ans);
       }
     }
     cout<<ans<<endl;
   }

  return 0;
}
