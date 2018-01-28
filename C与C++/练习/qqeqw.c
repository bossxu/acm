#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d",&a);scanf("%d",&b);
    change(&a,&b);
    printf("%d %d",a,b);
}
void change(int *pa,int *pb)
{

    int t;
    t=*pa;
    *pa=*pb;
    *pb=t;

}
