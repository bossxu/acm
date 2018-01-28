#include<stdio.h>
void Shu(int *a,int n )
{
    a[1]=3;
    a[2]=6;
    a[3]=6;
    int i;
    for(i=4;i<=n;i++)
    {
        a[i]=a[i-1]+2*a[i-2];
    }
}
int main()
{
    int n;
    int a[60];
    while(scanf("%d",&n)==1)
      {
          Shu(a,n);
          printf("%d\n",a[n]);
      }
    return 0;
}
