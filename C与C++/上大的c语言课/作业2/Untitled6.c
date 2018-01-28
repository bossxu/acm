#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
  if(a==0)
  {
      printf("not within the scope of judgment");
  }
  else
  {
      if(a>0)
      {
          if(a%2==0)
          {
              printf("positive even number");
          }
          else
          {
              printf("positive odd number");
          }
      }
      else
      {
          a=-a;
          if(a%2==0)
          {
              printf("negative even number");
          }
          else
          {
              printf("negative odd number");
          }
      }
      return 0;
  }










    return 0;
}
