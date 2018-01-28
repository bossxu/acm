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
bool check(char *c , int m,int l)
{
  int k=0;
  for(int i = 0; i<strlen(c)-l;i++)
  {
    k = k*10 + c[i]-'0';
  }
  if(m == k) return false;
  else return true;
}

int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int n;
   char a[10];
   int b;
   cin>>n;
      for(int i =1;i<=n;i++)
      {
        scanf("%s%d",a,b);
        int l = 0;
        int o = 0;
        while(check(a,b,l))
        {
          for(int i = 0 ;i<n;i++)
          {
            
          }
        }
      }
  return 0;
}
