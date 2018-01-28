#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main()
{
  int shu[105];
  int m,c=0;
  while(scanf("%d",&m)==1)
  {   c++;
      if(m==0) break;
      if(c!=1) printf("\n"); 
    int i,j,sum=0,big=0;
    for(i=0;i<m;i++)
    {
        scanf("%d",&shu[i]);
        sum+=shu[i];
    } 
    int avg=sum/m;
    for(i=0;i<m;i++)
    {
        if(shu[i]>avg) big+=shu[i]-avg;
    } 
    printf("%d\n",big);
  }
return 0;
}