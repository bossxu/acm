#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;
#define ui unsigned int
#define ull unsigned long long
ull a,b,c;
ui x,y,z;
// 这题真的打死都没有想到存前面100个大的数去操作，我真的没有想到
// 首先这边的这些东西是随机的，也就是没有什么规律，我要有点意识，是不是随机的
// 这里还有个规律就是，随机两个数的互质的概率是很大的，所以我记录一点点就ok了
// 可以说真的没有想到， 补题的意义在于去思考别人怎么想到这些东西的。
// 随机化算法，有点东西
ui tang()
{
  ui t;
  x ^= x<<16;
  x ^= x>>5;
  x ^= x<<1;
  t = x;
  x = y;
  y = z;
  z = t^x^y;
  return z;
}
ull gcd(ull a, ull b)
{
  return b == 0?a:gcd(b,a%b);
}
ull lcm(ull a,ull b)
{
  return a / gcd(a,b) * b;
}
ull shu[10000007];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  int n;
  int tot = 0;
  while(t--)
  {
    cout<<"Case #"<<++tot<<": ";
    cin>>n>>a>>b>>c;
    x = a,y = b,z = c;
    for(int i =1 ;i<=n;i++)
    {
      shu[i] = tang();
    }
    int t = min(101,n+1);
    nth_element(shu+1,shu+t,shu+n+1,greater<ull>());//这个是一个stl 就是存前t个最小的这个要知道
    ull maxn = 0;
    for(int i = 1;i<t;i++)
    {
      //cout<<shu[i]<<endl;
      for(int j = 1;j<i;j++)
      {
        maxn = max(maxn,lcm(shu[i],shu[j]));
      }
    }
    cout<<maxn<<endl;
  }
  return 0;
}
