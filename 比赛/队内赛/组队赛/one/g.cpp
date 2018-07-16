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
//思路具有巧妙的性质,无从推敲
//记忆化dp,他的思路在于把状态看成是否把这个字节变成我想变的字
//对于每个法让from和to来说,我的思路在于把所有的from变成to,这样的目的因为我们之前无法证明把什么变成什么是最优的
//这样的思路说实话在比赛中太难想到了
//然后这里记忆话的是变到这个字节的时候,我是否把这个字节变成我想要变的那个字符,变到这位以及可变的的次数
//这里的有个贪心的前提就是,都是变成一位,就是所有的k是加到一位是最优情况.
char s[100005];
int fre[27];
ll dp[5005][26];
ll res = 0;
int n,k,from,to;
ll op(int f, int ch)
{
  return 1LL*f*(f-1)/2*(ch+'a');
}
ll cal(int ch ,int rem)
{
  if(ch == from || ch == to) return cal(ch+1,rem);
  if(ch == 26)
  {
    int t = min(rem,fre[from]);
    rem -=t;
    return op(fre[from]-t,from)+op(fre[to]+k-rem,to);
  }
   ll &ret = dp[rem][ch];
   if(ret!=-1) return ret;
   ret = op(fre[ch],ch)+cal(ch+1,rem);
   if(rem-fre[ch]>=0)
   {
     ret = max(ret,cal(ch+1,rem-fre[ch]));
   }
   return ret;
}
int main()
{
//   freopen("in.txt","r",stdin);
//   freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    cin>>s;
    clr(fre,0);
    for(int i = 0;i<n;i++)
    {
      fre[s[i]-'a']++;
    }
    res = 0;
    for(int i = 0;i<=25;i++)
    {
      for(int j = 0;j<=25;j++)
      {
        if(i == j) continue;
        clr(dp,-1);
        to = i,from = j;
        res = max(res,cal(0,k));
      }
    }
    cout<<res<<endl;
  }
  return 0;
}
