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
int vis[5005][5005];
int main()
{
   char s[5005];
   int dp[5005];
   int sum ;
   while(cin>>s)
   {
     sum = 0;
     clr(vis,0);
     clr(dp,0);
     for(int i = 1;i<strlen(s);i++)
     {
       int c = 0;
       if(s[i] == '(')
       {
         continue;
       }
       if(s[i] == ')'|| s[i]=='?')
       {
         if(s[i-1] == '(' || s[i-1] == '?')
         {
           vis[i-1][i] =1;
           c++;
           if(i>2)
           {
             if(s[i-2] == ')' || s[i-2] =='?')
             {
               c+=dp[i-2];
               cout<<"->"<<i<<endl;
             }
           }
         }
          if(s[i]!='(')
          for(int j = 0;j<i-1;j++)
          {
            if(vis[j][i-1])
            {
              if(j!=0 && (s[j-1]=='('||s[j-1]=='?'))
              {
                  vis[j-1][i] = 1;
                  c++;
              }
            }
          }
       }
       dp[i] = c;
       sum+=c;
     }
     cout<<sum<<endl;
   }
  return 0;
}
