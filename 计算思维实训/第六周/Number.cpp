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
   int shu[4];
   int dp[20];
   int n;
   while(cin>>n)
   {
     clr(dp,0);
     if(n == 0)
     {
       break;
     }
     for(int i = 0;i<n;i++)
     {
       cin>>shu[i];
       dp[i] = shu[i];
     }
     int k = n;
     for(int i = 0;i<n;i++)
     {
       for(int j =i+1;j<n;j++)
       {
          dp[k++] = shu[i]+shu[j];
       }
     }
     for(int i = 0;i<n;i++)
       for(int j = i+1;j<n;j++)
         for(int l = j+1;l<n;l++)
        {
          dp[k++] = shu[i]+shu[j]+shu[l];
        }
     int i = 1;
     int j = 0;
     //cout<<k<<endl;
     sort(dp,dp+k);
     while(true)
     {
       //cout<<i<<endl;
        if(dp[j] == i)
        {
          j++,i++;
          continue;
        }
        if(j>= n*(n+1)/2)
        {
          break;
        }
        if(dp[j]<i)
        {
          j++;
        }
        if(dp[j]>i)
        break;
     }
     cout<<i<<endl;
   }
  return 0;
}
