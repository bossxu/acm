#include<stdio.h>
#include<math.h>
#include<string.h>
#define max 105
int Lu[max][max];
int dp[max][max];
int big(int a,int b, int c, int d)
{
	int z;
	z=a;
	if(b>z) z=b;
	if(c>z) z=c;
	if(d>z) z=d;
	return z;
}
int solve(int n,int m)
{
  memset(dp,0,sizeof(dp));
  int i,j,k=m*n;
  for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
		  if(Lu[i][j]==1) dp[i][j]=1;
while(k--)
	  {
	      for(i=1;i<=n;i++)
  {
	  for(j=1;j<=m;j++)
	  {
		  dp[i][j]=big((Lu[i][j]>Lu[i-1][j])*dp[i-1][j],(Lu[i][j]>Lu[i+1][j])*dp[i+1][j],(Lu[i][j]>Lu[i][j+1])*dp[i][j+1],(Lu[i][j]>Lu[i][j-1])*dp[i][j-1])+1;
	  }
  }
	  }
    int z=0;
  for(i=1;i<=n;i++)
{

	  for(j=1;j<=m;j++)
		 {
		     if(dp[i][j]>z)  z=dp[i][j];
		 }
}
	  return z;
}
int main()
{
	int n,m;
	int i,j,z;
	while(scanf("%d%d",&n,&m)==2)
	{
		memset(Lu,0,sizeof(Lu));
		 for(i=1;i<=n;i++)
			 for(j=1;j<=m;j++)
				 scanf("%d",&Lu[i][j]);
	     printf("%d\n", solve(n,m));
	}
	return 0;
}
