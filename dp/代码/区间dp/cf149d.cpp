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
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  char s[705];
  int a[705];
  while(scanf("%s",s)!=EOF)
  {
    getchar();
    int n = strlen(s);
    for(int i = 0;i<n;i++)
    {
      if(s[i] == '(') a[i] = 1;
      else a[i] = -1;

    }


  }

  return 0;
}
