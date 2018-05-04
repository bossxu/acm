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
int shu[100005];
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int n;
  while(cin>>n)
  {
    scanf("%s",s);
    if(n%4==0 || (n+1)%4==0)
    {
      if(n%4 == 0)
      {
        for(int i = 1;i<=n/2;i+=2)
        {
          shu[i] = 1;shu[n-i+1] = 1;
          shu[i+1] = 2;shu[n-i] = 2;
        }
        for(int i = 1;i<=n;i++)
        {
          if(s[i-1]=='0' && shu[i] == 1) cout<<"1";
          if(s[i-1]=='0' && shu[i] == 2) cout<<"2";
          if(s[i-1] == '1' && shu[i] == 1) cout<<"3";
          if(s[i-1] == '1' && shu[i] == 2) cout<<"4";
        }
      }
      else
      {
        shu[n] = 2;
        for(int i = 1;i<=n-1;i+=2)
        {
          shu[i] = 1;shu[n-i] = 1;
        }
        for(int i = 2;i<=n-1;i+=2)
        {
          shu[i] = 2;shu[n-i] = 2;
        }
        for(int i = 1;i<=n;i++)
        {
          if(s[i-1]=='0' && shu[i] == 1) cout<<"1";
          if(s[i-1]=='0' && shu[i] == 2) cout<<"2";
          if(s[i-1] == '1' && shu[i] == 1) cout<<"3";
          if(s[i-1] == '1' && shu[i] == 2) cout<<"4";
        }
      }
    }
    else
    cout<<"-1"<<endl;
  }
  return 0;
}
