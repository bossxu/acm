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
const int maxn = 10005;
// 双重循环 ，t了;没办法了，可以麻烦一点，就是利用 结构体来吧这个部分背包转换成01背包;
// 很慢，网上看到一个算法，速度很快;我觉得思路方向没错但是，这题用这个算法会gg
// 多重背包的 路径记录问题
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int p;
    vector<int>dp[maxn];
    int c[5];
    int a[5]={0,1,5,10,25};
    while(cin>>p>>c[1]>>c[2]>>c[3]>>c[4])
    {
      if(!(p || c[1] || c[2] || c[3] || c[4] ))
      {
        break;
      }
      for(int i =0;i<=p;i++)
      {
        dp[i].clear();
      }
      for(int i= 1;i<=4;i++)
      {
        for(int j=p;j>=a[i];j--)
        {
          for(int k=1;k<=c[i];k++)
          {
            if ( j>=a[i]*k&& (dp[j-a[i]*k].size()!=0 || j==a[i]*k) && dp[j-a[i]*k].size()+k > dp[j].size())
            {
              dp[j]= dp[j-k*a[i]];
              for(int l=0;l<k;l++)
                dp[j].push_back(a[i]);
            }
          }
        }
      }
        int num[26];
        clr(num,0);
        for(int i=0;i<dp[p].size();i++)
        {
          num[dp[p][i]]++;
        }
        if(p == num[1]+num[5]*5+num[10]*10+num[25]*25)
        printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",num[1],num[5],num[10],num[25]);
        else
        printf("Charlie cannot buy coffee.\n");
    }
    return 0;
}
