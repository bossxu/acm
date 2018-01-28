#include<string.h>
#include<stdio.h>
#include<math.h>
#define N 8000
int money[]={1,5,10,25,50};
int cnt[N];
void Init()
{
    int i,j;
    memset(cnt,0,sizeof(cnt));
    cnt[0]=1;

    for(i=0;i<5;i++)
    {
        for(j=money[i];j<N;j++)
        {
            cnt[j]+=cnt[j-money[i]];
        }
    }
}
int main()
{
    int a,b,c,d;
    int s,f,count=0;
    Init();
    while(scanf("%d",&s)==1)
    {
       printf("%d\n",cnt[s]);
    }
    return 0;
}
