#include<stdio.h>
int su(int k)
{
    int i,j;
    for(i=2;i<k;i++)
    {
        if(k%i==0) return 0;


    }
    if(k==i) return k;
}
int ji(int n)
{
    int i,j,s;

        for(i=2;i<n;i++)
   {
       for(j=2;j<i;j++)
       {
           if(i%j==0) break;

       }

       if(i==j)
       {
           s=n;
           if(n%i==0)
           printf("%d*",i);s=s/i;
           return s; break;
       }

   }


}
int main()
{
   int j, i,n,k,s;
   scanf("%d",&n);k=n;s=k;

  while(1)
  {

    k=s;n=k;
    if(su(k)==0)
       s= ji(k);
else
    printf("%d",k);

  }


    return 0;
}
