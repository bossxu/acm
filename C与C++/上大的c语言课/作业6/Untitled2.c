#include<stdio.h>
void pan(int n,int B[])
{
    int i;
    for(i=0;i<5;i++)
    {
        if(n==B[i])
        {
            printf("%d ",n);
            break;
        }
    }
}
int main()
{
    int i,j,A[5],B[5];
    printf("Please Enter Array A,5 digits: ");
    for(i=0;i<5;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Please Enter Array B,5 digits: ");
    for(i=0;i<5;i++)
    {
        scanf("%d",&B[i]);
    }

    printf("A B intersection is:");
    for(j=0;j<5;j++)
    {
        pan(A[j],B);
    }


    return 0;
}
