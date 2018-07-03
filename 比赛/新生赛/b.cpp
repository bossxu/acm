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
char s[105];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    cin>>s;
    for(int i = 0;i<strlen(s);i++)
    {
      int k = s[i]-'a'+1;
      if(k<10) cout<<0<<k;
      else cout<<k;
    }
    cout<<endl;
  }
  return 0;
}
