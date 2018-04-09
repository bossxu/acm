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
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
char s[100006];
int main()
{
  //freopen("out.txt","r",stdin);
   int t;
   cin>>t;
   while(t--)
   {
     int n;
     cin>>n;
     cin>>s;
     int len = strlen(s);
     int flag = 2*n-2;
     if(n== 1)
     {
       for(int i = 0;i<len;i++)
       cout<<s[i];
       cout<<endl;
       continue;
     }
     for(int i = 0;i<len;i+=flag)
     {
       cout<<s[i];
     }
     for(int i = 1;i<n-1;i++)
     {
       if(i>=len) break;
       for(int j = i;j<len;j+=flag)
       {
          cout<<s[j];
          int p = j+(n-i-1)*2;
          if(p<len)
          cout<<s[p];
       }
     }
     for(int i = n-1;i<len;i+=flag)
     {
       cout<<s[i];
     }
    cout<<endl;
   }

  return 0;
}
