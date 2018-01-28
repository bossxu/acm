#include<stdio.h>
#include<string.h>
#define maxsize 10005
int main()
{
    int i,j;
    int a,b,c,d,t;
    int shu[maxsize];
    while(scanf("%d",&t)==1)
    {
        while(scanf("%d%d%d%d",&a,&b,&c,&d)==4)
        {
              memset(shu,0,sizeof(shu));
            for(i=b;i<maxsize;i+=a) shu[i]++;
            for(i=d;i<maxsize;i+=c) shu[i]++;
            j=-1;
            for(i=0;i<maxsize;i++)
                if(shu[i]==2)
                {
                  j=i;break;
                }
              printf("%d\n",j);
        }
    }
    return 0;
}
