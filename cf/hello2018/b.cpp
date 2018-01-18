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
  int n;
  while(cin>>n)
  {
    int shu[1005];
    int vis[1005];
    int hash[1005];
    clr(hash,0);
    clr(vis,0);
    for(int i = 2;i<=n;i++)
    {
      cin>>shu[i];
      vis[shu[i]] = 1;
    }
   for(int i = 2;i<=n;i++)
   {
     if(!vis[i])
      hash[shu[i]]++;
   }
   int flag = 1;
   for(int i = 1;i<=n;i++)
   {
     //cout<<hash[i]<<endl;
     if(hash[i]!=0 && hash[i]<3)
     {
       flag = 0;
     }
   }
  if(flag)
  {
    cout<<"Yes"<<endl;
  }
  else
  cout<<"No"<<endl;
  }


  return 0;
}
