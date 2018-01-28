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

    int x,y;
 scanf("%d",&x);
 if(su(x)==0)
 {

 for(y=2;y<=x;y++)
 {
  if(x%y==0)
  {
   x=x/y;
   printf("%d*",y);
   y--;
  }
  else
  {
   continue;
  }
 }}
 else printf("%d",su(x));

    return 0;
}
