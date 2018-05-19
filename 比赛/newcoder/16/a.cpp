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
char s[100005];
char ans[100005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(scanf("%s",s)!=EOF)
  {
    int tot = 0;
    ans[0] = s[0];
    //cout<<s<<endl;
    for(int i = 1;i<strlen(s);i++)
    {
    while(tot>=0 && s[i]>ans[tot])
    {
      tot--;
    }
    ans[++tot] = s[i];
    }
    for(int i = 0;i<=tot;i++)
    {
      cout<<ans[i];
    }
    cout<<endl;
  }

  return 0;
}
