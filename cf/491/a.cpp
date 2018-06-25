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
#define clr(a,x) memset(a,x,sizeof(a))
int main()
{
  std::ios::sync_with_stdio(false);
  int a,b,c,n;
  while(cin>>a>>b>>c>>n){
  int ans = n+c-a-b;
  int flag = 1;
  if(max(a,b)>n || c>min(a,b)) flag = 0;
  if(ans<=0 || !flag)
  {
    cout<<-1<<endl;
  }
  else
  {
    cout<<ans<<endl;
  }
}
  return 0;
}
