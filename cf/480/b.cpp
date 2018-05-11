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
int s[5][105];
void pri(int n)
{
  for(int i = 1;i<=4;i++)
  {
    for(int j = 1;j<=n;j++)
    {
      if(s[i][j]) cout<<"#";
      else cout<<".";
    }
    cout<<endl;
  }
}
int main()
{
  int n,k;
  while(cin>>n>>k)
  {
    clr(s,0);
    if(k%2 == 0)
    {
      cout<<"YES"<<endl;
      for(int i = 1;i<=k/2;i++)
      {
        s[2][i+1] = 1;
        s[3][i+1] = 1;
      }
      pri(n);
    }
    else
    {
      if(k == n-2)
      {
        cout<<"YES"<<endl;
        for(int i = 2;i<n;i++)
        {
          s[2][i] = 1;
        }
        pri(n);
      }
      else
      {
        if(k>=5)
        {
          cout<<"YES"<<endl;
          int p = k/2;
          for(int i = 1;i<=p-1;i++)
          {
            s[2][i+1] = 1;
            s[3][i+1] = 1;
          }
          s[2][p+1]=1;
          s[2][p+2] = 1;
          s[3][p+2] =1;
          pri(n);
          continue;
        }
        if(k == 1)
        {
          cout<<"YES"<<endl;
          s[2][n/2+1] = 1;
          pri(n);
          continue;
        }
        if(k == 3)
        {
          cout<<"YES"<<endl;
          s[2][n/2+1] = 1;
          s[3][n/2] = 1;
          s[3][n/2+2] = 1;
          pri(n);
        }
      }


    }
  }
  return 0;
}
