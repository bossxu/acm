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
bool check(int i,int j)
{
  if(i%10 == 7)
  {
    return 1;
  }
  if(j%10 == 7)
  {
    return 1;
  }
  return 0;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n;
  while(cin>>n)
  {
    getchar();
    char s[6];
    gets(s);
    int o = s[0]-'0';
    o = o*10+s[1]-'0';
    int p = s[3]-'0';
    p = p*10+s[4]-'0';
    int num = 0;
    while(!check(o,p))
    {
      num++;
      p-=n;
      if(p<0)
      {
        o = (o-1+24)%24;
        p+=60;
      }
    }
    //cout<<o<<p<<endl;
    cout<<num<<endl;
  }
  return 0;
}
