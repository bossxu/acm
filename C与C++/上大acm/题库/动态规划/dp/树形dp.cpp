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
const int maxn = 6006;
// 知识点分解：
int dp[maxn][2];//前面是人的编号，后面是来或者不来
int father[maxn],vis[maxn];
int n;
void tree_dp(int node)
{
    int i;
    vis[node]=1;
    for(i=1;i<=n;i++)
    {
        if( !vis[i] && father[i]==node)
        {
            tree_dp(i);
            dp[node][1]+=dp[i][0];
            dp[node][0]+=max(dp[i][0],dp[i][1]);
        }
    }
}
int main()
{
   while(cin>>n)
   {
       clr(dp,0);
       clr(vis,0);
       clr(father,0);
       for(int i=1;i<=n;i++)
       {
           cin>>dp[i][1];
       }
       int a,b;
       int root = 0;
       while(cin>>a>>b && (a||b))
       {
           father[a]=b;
           root =b ;
       } 
       while(father[root])
       {
           root =father[root];
       }        
       tree_dp(root);
       printf("%d\n",max(dp[root][0],dp[root][1]));
       
   }
    return 0;
}