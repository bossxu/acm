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
char s[105];
int dp[2];
int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int n;
   while(cin>>n)
   {
     scanf("%s",s);
     clr(dp,0);
     int index = 0;
     for(int i = 0;i<n;i++)
     {
       dp[s[i]-'0']++;
     }
     if(dp[1] == 0)
     {
       cout<<"0"<<endl;
     }
     else
     {
       cout<<"1";
       for(int i=1;i<=dp[0];i++)
       cout<<"0";
       cout<<endl;
     }
   }
  return 0;
}
