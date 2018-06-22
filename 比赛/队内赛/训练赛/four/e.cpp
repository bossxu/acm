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
struct Node
{
  int num;
  char op;
}s[2][1000005];
char p[1000005];
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  while(cin>>p)
  {
    int num = 0;
    int flag = 1;
    int st = 1;
    int a[2];
    a[0] = strlen(p);
    int item = 0;
    num = 1;
    for(int i = 1;i<a[0];i++)
    {
      if(p[i]!=p[i-1])
      {
        s[0][item].op = p[i-1];
        s[0][item++].num = num;
        num = 1;
      }
      else
      num++;
    }
    s[0][item].op = p[a[0]-1];
    s[0][item++].num = num;
    a[0] = item;
    num = 0;
    while(a[st^1]>1)
    {
      a[st] = 0;
      num++;
      st^=1;
      s[st][0].num-=1;
      if(s[st][0].num>0)
      {
        s[st^1][a[st^1]++] = s[st][0];
      }
      //cout<<a[st^1]<<" --- "<<endl;

      for(int i = 1;i<a[st]-1;i++)
      {
        s[st][i].num-=2;
        if(s[st][i].num>0)
        {
          if(a[st^1] > 0 && s[st^1][a[st^1]-1].op == s[st][i].op)
          {
            s[st^1][a[st^1]-1].num+=s[st][i].num;
          }
          else
          s[st^1][a[st^1]++] = s[st][i];
        }
      }
      s[st][a[st]-1].num-=1;
      if(s[st][a[st]-1].num>0)
      {
        if(a[st^1]>0 && (s[st^1][a[st^1]-1].op == s[st][a[st]-1].op))
          s[st^1][a[st^1]-1].num += s[st][a[st]-1].num;
        else
          s[st^1][a[st^1]++] = s[st][a[st]-1];
      }
      //cout<<a[st^1]<<" --- "<<endl;
    }
    cout<<num<<endl;
  }

  return 0;
}
