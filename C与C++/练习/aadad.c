#include<stdio.h>
void main()
{
  int i,k,n,sum=0,count=0;
  printf("Input an integer:");
  scanf("%d",&n);
  k=n;
  while (k!=0)
 {
     k=k/10;
     count++;
 }
  printf("count=%d ",count);
  for(i=1;i<=count;i++)
  {
     sum=sum+n%10;
     n=n/10;
  }
  printf("sum=%d",sum);
}

