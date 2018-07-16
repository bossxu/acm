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
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n,t;
  cin>>t;
  while(t--)
  {
    int flag = 0;
    cin>>n;
    int a;
    int minn = 1000005;
    for(int i = 1;i<=n;i++)
    {
      cin>>a;
      minn = min(a,minn);
      flag = (flag+a)%2;
    }
    if(n%2)
    {
      if(flag)
      {
        cout<<"Yalalov"<<endl;
      }
      else
      {
        cout<<"Shin"<<endl;
      }
    }
    else
    {
      if(minn%2)
      {
        cout<<"Yalalov"<<endl;
      }
      else
      {
        if(!flag)
        {
          cout<<"Shin"<<endl;
        }
        else
        {
          cout<<"Yalalov"<<endl;
        }
      }
    }
  }
  return 0;
}
