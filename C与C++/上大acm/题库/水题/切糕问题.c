#include<stdio.h>
int shuchu(int n)
{
    if(n==1)
    {
        printf("Mission Complete!\n");
        return ;
    }
    int i,j=0;
    for(i=n-1;i>0;i--)
    {
        j=j+i;
    }
    printf("Needs at least %d ATP(s)!\n",j);
    return ;
}
int main()
{
    int i,j,k,Ene;
    int shu[100];
    scanf("%d",&k);
    for(i=0;i<k;i++)
   {
       scanf("%d",&shu[i]);
   }
    for(j=0;j<k;j++)
    {
        shuchu(shu[j]);
    }
    return 0;
}
