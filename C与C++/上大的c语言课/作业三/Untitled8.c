#include<stdio.h>
int main()
{
    int a,b,i,j,it;
    printf("Input m: Input n: ");
    scanf("%d%d",&a,&b);

    it=0;
    for(i=a;i<b;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
                break;}

            if(j==i)
           {

           printf("%4d",i);
            it=it+1;
            if(it%6==0)
                {
                    printf("\n");}

    }}



    return 0;
}
