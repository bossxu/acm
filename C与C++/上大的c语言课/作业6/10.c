#include<stdio.h>
int main()
{
    int n,num[100],x;
    int i=0,j=0;
    printf("Input n:");scanf("%d",&n);
    printf("Input %d integers:",n);
    for(;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    printf("Input x:");scanf("%d",&x);
    search(num,n,x);


    return 0;
}
void search(int num[100],int n,int x)
{
    int i=0;
    for(;i<n;i++)
    {
        if(x==num[i])
        {
            printf("index = %d",i);
            break;
        }
    }
     if(i==n) printf("Not found") ;

}
