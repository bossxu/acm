#include<stdio.h>
void pan(int k[],int n)
{
    int i,j,L[10];
    for(j=0;j<10;j++)
    {
        i=j-n;if(i<0) i=i+10;
        L[i]=k[j];
    }
    for(j=0;j<10;j++)
    {
     k[j]=L[j];
    }

}
int main()
{
    int i,j,a[10];
    printf("Enter 10 integers: ");
    for(i=0;i<10;i++)
    {
     scanf("%d",&a[i]);
    }
    int x;
    printf("Enter x: ");
    scanf("%d",&x);
    printf("After Circle left shift %d bit: ",x);
    pan(a,x);
    for(i=0;i<10;i++)
    {
        printf("%4d",a[i]);
    }
    return 0;
}
