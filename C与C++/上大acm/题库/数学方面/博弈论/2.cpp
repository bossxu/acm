#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005
using namespace std;
int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        int sum=0,ans=0,c[1005],dp[1005];
        dp[0]=0;
      for(int i=1;i<=n;i++)
      {
          scanf("%d",&c[i]);
      }
      sort(c+1,c+n+1);
      for(int i=1;i<=n;i++)
      {
          dp[i]=c[i]-c[i-1]-1;
          if( (n-i+1)%2==1 ) sum^=dp[i];
        
      }
        if(sum==0)
        printf("Bob will win\n");
        else 
        printf("Georgia will win\n");
    }
    //system("pause");
  return 0;
}