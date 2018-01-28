#include<stdio.h>
#include<math.h>
int danan(int m,int n,int MOD)
{
    if(n==1) return m%MOD;
    if(n==0) return 1;
     if(n%2==1)
      return danan(m,n/2,MOD)*danan(m,n/2,MOD)*danan(m,1,MOD)%MOD;
     else
       return danan(m,n/2,MOD)*danan(m,n/2,MOD)%MOD;
}
int pan(int a)
{
    int i;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0) return 0;
    }
    return 1;
}
int main()
{
     int a,b;
     while(scanf("%d%d",&a,&b)==2)
     {
         if(!pan(a))
         {
             if(b%a==danan(b,a,a))
                printf("yes\n");
            else
                printf("no\n");
         }
         else
            printf("no\n");
     }
    return 0;
}
