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
// 知识点分解：dfs 解二维背包
int a[45];
int n,m,ans;
int k;
void dfs(int t,int i, int x)
{
    ans=max(ans,x);
   if(i>k) return ;
   if(t+1<=n && x+a[i]<=m)
   {
       dfs(t+1,i+1,x+a[i]);
   }
   dfs(t,i+1,x);
}
bool cmp(int a, int b) {return a>b;}
int main()
{
    while(cin>>n>>m)
    {
        cin>>k;
        int sum=0;
        for(int i=1;i<=k;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+k+1,cmp);
        for(int i=1;i<=n;i++)
       {
          sum+=a[i];
       }
       if(sum<=m)
        {
            cout<<sum<<endl;
            continue;
        }
        ans = 0;
        dfs(0,1,0);
        cout<<ans<<endl;
    }
    return 0;
}