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
bool isPrime( int num )
{
  if(num == 1)
  return 0;
     int tmp =sqrt( num);
     for(int i= 2;i <=tmp; i++)
        if(num %i== 0)
          return 0 ;
     return 1 ;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n;
  ll m;
  while(cin>>n>>m)
  {
    int j = n-1;
    while(!isPrime(j))
    {
      j++;
    }
    cout<<j<<" "<<j<<endl;
    int l = n-1;
    int i = 1,k = 3;
    for(int o = 1;o<n-1;o++)
    {
      cout<<o<<" "<<o+1<<" 1"<<endl;
    }
    cout<<n-1<<" "<<n<<" "<<j+2-n<<endl;
    while(l<m)
    {
      if(k-i == 1) continue;
      l++;
      cout<<i<<" "<<k<<" "<<j+1<<endl;
      k++;
      if(k>n)
      {
        i = i+1;
        k = i+2;
      }
    }
  }

  return 0;
}
