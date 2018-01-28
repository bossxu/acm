#include<stdio.h>
void Cha_two(int *s,int k,int l,int r)
{
    int i,j;
    while(r>l)
    {
        if(s[l+(r-l)/2]==k)
        {
            printf("Yes\n");
            return;
        }
        else if(s[l+(r-l)/2]>k)
        {
            r=l+(r-l)/2-1;
        }
        else
        {
            l=l+(r-l)/2+1;
        }
    }
    if(s[l+(r-l)/2]==k)
    {
        printf("Yes\n"); return;
    }
    else
    {
        printf("No\n") ;return;
    }
}
int main()
{
    int N,M,Shu[100005],x;
    int i,j;
    while(scanf("%d%d",&N,&M)==2)
    {
        for(i=0;i<N;i++)
            scanf("%d",&Shu[i]);
        while(scanf("%d",&x)==1)
            Cha_two(Shu,x,0,M);
    }
    return 0;
}
