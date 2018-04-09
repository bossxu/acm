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
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int dp[31];
int maxn = 0;
void dfs(int i,int j,int flag)
{
   maxn = max(j,maxn);
   if(i>30) return ;
   if(flag == 0)
   {
     dfs(i+1,j,0);
     dfs(i+1,j,1);
   }
   else
   {
     dfs(i+1,j^dp[i],0);
     dfs(i+1,j^dp[i],1);
   }
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
   for(int i = 1;i<=30;i++)
   {
     cin>>dp[i];
   }
   dfs(1,0,0);
   dfs(1,0,1);
   cout<<maxn<<endl;
   getchar();
  return 0;
}
