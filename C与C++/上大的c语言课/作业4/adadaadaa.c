#include "stdio.h"
#include "conio.h"
main()
{
  int n,i;
  printf("Input an integer: ");
  scanf("%d/n",&n);
  printf("%d=",n);
  for(i=2;i<=n;i++)
    while(n!=i)
    {
      if(n%i==0)
      {
        printf("%d*",i);
        n=n/i;
      }
      else
        break;
    }
  printf("%d",n);
  getch();
}
