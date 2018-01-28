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
int main()
{
   int j, i,n,k,s;
   printf("Input an integer: ");
   scanf("%d",&n);k=n;s=n;
  printf("%d=",n);
s=0; int arr[100];
  while (su(k)==0)
  {
      for(i=2;i<k;i++)
      {
          for(j=2;j<i;j++)
          {
              if(i%j==0) break;
          }
          if(i==j)
          {
              if(k%i==0)
              {
                  arr[s]=i;
                  k=k/i;
                  s++;
              }
          }
      }

  }
   arr[s]=k;int t;
  for(i=1;i<=s;i++)
  {
      for(j=0;j<=s-1;j++)
     {
         if(arr[j]>arr[j+1])
         {
             t=arr[j];arr[j]=arr[j+1];arr[j+1]=t;
         }
     }
  }
for(i=0;i<s;i++)
{
    printf("%d*",arr[i]);
}
printf("%d",arr[s]);

    return 0;
}
