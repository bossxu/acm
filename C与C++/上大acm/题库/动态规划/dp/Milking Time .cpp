#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
#define maxn 0x3f3f3f3f
struct se{
   int st,end,xiao;
}node[1005];
int cmp(se a, se b)
{
    if(a.end<b.end)
    {
        return 1;
    }
    if(a.end==b.end)
    {
        if(a.st<b.st)
        return 1;
    }
    else return 0;
}
int main()
{
  int dp[1000005];
   int N,M,R;
   while(cin>>N>>M>>R)
   {
       for(int i=1;i<=M;i++)
       {
           scanf("%d%d%d",&node[i].st,&node[i].end,&node[i].xiao);
       }
       memset(dp,0,sizeof(dp));
       sort(node+1,node+M+1,cmp);
      /* for( int i=1;i<=M;i++)
        printf("%d\n",node[i].st);*/
       for(int i=1;i<=M;i++)
       {
           for(int j=N;j>=node[i].end;j--)
           {
               if(node[i].st>=R)
                dp[j]=max(dp[j],dp[node[i].st-R]+node[i].xiao);
                else
                dp[j]=max(dp[j],dp[node[i].st]+node[i].xiao);
           } 
       }
       printf("%d\n",dp[N]);
   }
    return 0;
}