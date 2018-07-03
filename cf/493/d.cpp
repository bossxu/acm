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
ll ans[20];
void init(){
ans[1] = 4;
ans[2] = 10;
ans[3] = 20;
ans[4] = 35;
ans[5] = 56;
ans[6] = 83;
ans[7] = 116;
ans[8] = 155;
ans[9] = 198;
ans[10] = 244;
ans[11] = 292;}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  init();
  while(cin>>n)
  {
    if(n<=11)
    {
      cout<<ans[n]<<endl;
    }
    else
    {
      cout<<1LL*(n-11)*49+ans[11]<<endl;
    }
  }
  return 0;
}
