#include<stdio.h>
int main()
{
    int a,b,c;
    int i,j,k,item;
    int q,w,e;
    int count=0;
    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        q=0;w=0;e=0;item=0;
        for(i=100;i>0&&!item;i--)
            for(j=100;j>0&&!item;j--)
                for(k=99;k>0&&!item;k-=3)
                    if(a*i+b*j+(k/3)*c==100 && i+j+k==100)
                    {
                        q=i;w=j;e=k ;
                        item=1;
                    }
        printf("case %d:\n",++count);
        if( a*q+b*w+(e/3)*c==100 && q+w+e==100)
            printf("%d %d %d\n",q,w,e);
        else
            printf("Impossible\n");
    }
    return 0;
}
