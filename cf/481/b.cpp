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
#define ll unsigned long long
#define clr(a,x) memset(a,x,sizeof(a))
char s[105];
int main()
{
  int n;
  while(cin>>n)
  {
    scanf("%s",s);
    int len = strlen(s);
    int ans = 0;
    int item = 0;
    for(int i = 0;i<len;i++)
    {
      if(s[i] == 'x')
      {
        item++;
      }
      if(s[i]!='x')
      {
        if(item >=3)
        ans+=item-2;
        item = 0;
      }
    }
    if(item>=3)
    {
      ans+=item-2;
    }
    cout<<ans<<endl;
  }
  return 0;
}
