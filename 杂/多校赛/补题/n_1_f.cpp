#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
//自然数幂和的一个模型
//一个方法是用拉格狼日插值定理，一个是用柏奴力数
//都是不会的东西
//学点东西
//拉格朗日插值法适用的是，在平面有个确定的多次函数，然后我们也知道有几个点过这个函数
//然后这个时候我们就可以求出这个函数，他们的系数我们可以通过一种转换方式来求出来。
//或者说我们甚至可以不用求出来这个
int n;
ll shu[1005];
int main()
{
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    sort(shu+1,shu+n+1);

  }
  return 0;
}
