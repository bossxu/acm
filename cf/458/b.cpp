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
int check(string a, string b)
{
  if(a.length() ==  b.length()+1)
  {
    string c(a,0,b.length());
    //cout<<c<<"->"<<b<<endl;
    if(c == b)
    return true;
  }
  return false;
}
int main()
{
   string s[5][1005];
   int n,m;
   while(cin>>n>>m)
   {
      char o[100],p[100];
      for(int i = 1;i<=n;i++)
      {
        scanf("%s",o);
        s[1][i] = o;
        scanf("%s",p);
        s[2][i] = p;
      }
      for(int i = 1;i<=m;i++)
      {
        scanf("%s",o);
        s[3][i] = o;
        scanf("%s",p);
        s[4][i] = p;
      }
      for(int i = 1;i<=m;i++)
      {
        for(int j=1;j<=n;j++)
        {
          if(check(s[4][i],s[2][j]))
          {
            cout<<s[3][i]<<" "<<s[4][i]<<" #"<<s[1][j]<<endl;
            break;
          }
        }
      }

   }

  return 0;
}
