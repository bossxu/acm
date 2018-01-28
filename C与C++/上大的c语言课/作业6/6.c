#include<stdio.h>
int main()
{
    int a,n,i,sum=0;
    printf("Input a: ");scanf("%d",&a);
    printf("Input n: ");scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum=sum+fn(a,i);
    }
    printf("sum=%d",sum);

    return 0;
}
int fn(int a,int n)
{
  int dan=0,i=1;
  for(;i<=n;i++)
  {
      dan=dan*10+a;
  }
    return dan;


}
