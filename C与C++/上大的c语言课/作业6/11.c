#include<stdio.h>
int main()
{
    int num[100],n;
    printf("Input n: ");scanf("%d",&n);
    printf("Input array of %d integers: ",n);
    int i,j;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    pai(num,n);
    printf("After sorted the array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    return 0;
}
void pai(int n[],int a)
{
    int i,j,index,t;
    for(i=0;i<a-1;i++)
    {
        index=i;
        for(j=i+1;j<a;j++)
        {
            if(n[index]>n[j]) index=j;
        }
        t=n[index];
        n[index]=n[i];
        n[i]=t;

    }

}
