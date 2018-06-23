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
char s[20005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  while(cin>>s)
  {
    int ans = 1;
    int len = strlen(s);
    int item = INF;
    if(len == 1 && s[0] == '1')
    {
      cout<<1<<endl;
      continue;
    }
    for(int i = 1;i<len;i++)
    {
      if(s[i] == '1')
      {
        ans++;
      }
    }
    int num = 0;
    for(int i = 1;i<len;i++)
    {
      if(s[i]=='1')
      {
        num = len-i;
        break;
      }
    }
    ans = max(ans,num);
    int k = (1+len-1)*(len-1)/2;
    cout<<k+ans-1<<endl;

  }
  return 0;
}
