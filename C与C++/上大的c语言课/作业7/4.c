#include<stdio.h>
struct txl
{
    char name[10];
    int year;
    char number[20];
};
int main()
{
    int n,i,j,k;
    printf("Input n:");scanf("%d",&n);
    struct txl tat[10];
    struct txl p;

    for(i=0;i<n;i++)
    {
        printf("Input the name,age,telephone of the %d friend:",i+1);
        scanf("%s%d%s",tat[i].name,&tat[i].year,tat[i].number);
    }
printf("after sorted:\n");
for(i=0;i<n;i++)
{
    for(j=i+1;j<n;j++)
    {
        if(tat[i].year>tat[j].year)
        {
            p=tat[i];tat[i]=tat[j];tat[j]=p;
        }
    }
    printf("%s %d %s\n",tat[i].name,tat[i].year,tat[i].number);
}

    return 0;
}
