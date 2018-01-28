#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main()
{
  int a,b,c,d,count = 0;
  int dp[100],zp[5];
  while(scanf("%d%d%d%d",&zp[0],&zp[1],&zp[2],&zp[3])==4)
  {
       count++;
       if(count!=1)
       {
           if(zp[0]==0 & zp[1]==0 && zp[2]==0 && zp[3]==0)
           break;
           else printf("\n");
       }
      int cou=0 ;int i,j,k,m;
      for(i=0;i<4;i++)
      {
          for(j=0;j<4;j++)
          {
              for(k=0;k<4;k++)
              {
                  for(m=0;m<4;m++)
                  {
                      if( i==j || j==k ||k== m ||i==m||i==k ||j==m ) continue;
                     dp[cou++]=zp[i]*1000+zp[j]*100+zp[k]*10+zp[m];
                  }
              } 
          }
      }
      sort(dp,dp+cou);
      int u=0;
      for(i=0;i<24;i++)
        {
           if(dp[i]<1000) continue;
           if(dp[i]==dp[i-1]) continue;
           while(dp[i]>1000 && i<24)
           {
               int a = dp[i]/1000;
               printf("%d",dp[i]);
                while(dp[i]==dp[i+1])
                 {
                   i++;
                 }             
               if(dp[i+1] /1000 != a)
               {
                   printf("\n");break;
               } 
               else
               {
                   printf(" ");i++;
               }
           } 
        }
  }
    return 0;
}