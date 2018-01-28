#include<stdio.h>
#define maxsize 105

int main()
{
   int n,m;
   int i=0,j,k,count=0;
   int  a[maxsize];
   while(scanf("%d%d",&n,&m)==2)
   {
       getchar();
       for(i=0;i<n;i++)
       {
           scanf("%d",&a[i]);
       }
      j=0;k=0;
      while(1)
      {
           if(a[j%n]!=0) k++;
           if(k==m)
           {
               m=a[j%n];
             a[j%n]=0;
             count++;
             k=0;
            }
            j++;
            //printf("%d  %d\n",j,k);
            if(count==n-1)
                break;
      }
      for(i=0;i<n;i++)
      {
          if(a[i]!=0) printf("%d\n",i+1);
      }
   }
    return 0;
}
