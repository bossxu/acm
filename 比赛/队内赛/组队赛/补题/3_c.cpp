#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
//好题，没想到，这是一种暴力的思想
//枚举每个状态，假定这个状态是最后的正确答案然后进行处理。
//菜队的那个代码可以说有点好看的了
//掌握到了
string s = "shdc";
int getch(char a)
{
  for(int i = 0;i<4;i++)
  {
    if(a == s[i]) return i;
  }
}
int getid(char a,bool up)
{
   int ret ;
   if(isdigit(a)) ret = a - '2';
   if(a == 'T') ret = 8;
   if(a == 'A') ret = 12;
   if(a == 'Q') ret = 10;
   if(a == 'J') ret = 9;
   if(a == 'K') ret = 11;
   return up?12-ret:ret;
}
int dp[100];
int ko(const vector<int>& a,int n)
{
  clr(dp,INF);
  for(int i = 0;i<n;i++) *lower_bound(dp,dp+n,a[i]) = a[i];
  return lower_bound(dp,dp+n,INF)-dp;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while(cin>>n)
  {
    vector<string>q(n);
    for(auto& t : q) cin>>t;
    int ans = 0;
    sort(s.begin(),s.end());
    vector<int> a(n);
    do
    {
      for(int st = 0;st<(1<<4);st++)
      {
        for(int i = 0;i<n;i++)
        {
          int c = getch(q[i][1]);
          int d = getid(q[i][0],(st>>c)&1);
          a[i] = c*13 + d;
        }
        ans = max(ans,ko(a,n));
      }
    }
    while(next_permutation(s.begin(),s.end()));
    cout<<n-ans<<endl;
  }
  return 0;
}
