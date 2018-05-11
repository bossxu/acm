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
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(cin>>s)
  {
    int a = 0,b =0;
    for(int i = 0;i<strlen(s);i++)
    {
      if(s[i]=='o') a++;
      if(s[i]=='-') b++;
    }
    if(a == 1 || a == 0) cout<<"YES"<<endl;
    else
    {
      if(b%a == 0) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
  }
  return 0;
}
