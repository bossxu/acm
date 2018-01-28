#include<stdio.h>
int pan(int num[],int n);
int main()
{
int n,i;
printf("Input n:");scanf("%d",&n);
int num[20];
for(i=1;i<n;i++) num[i]=i;
num[0]=n;
int j=0,item=2;
for(i=0;item>1;i++)
{
    i=i%n;
    if(num[i]!=0) j++;

    if(j%3==0&&num[i]!=0)
        {
            num[i]=0;
            printf("%d ",i+1);
        }
    item=pan(num,n);//printf("item=%d j=%d  \n",item,j);

}
putchar('\n');
printf("Last No. is:%d",find(num,n));
    return 0;
}
int pan(int num[],int n)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        if(num[i]!=0) j++;
    }

    return j;
}
int find(int num[],int n)
{
    int i=0;
    for(;i<n;i++)
    {
        if(num[i]!=0) return i+1;
    }
}
