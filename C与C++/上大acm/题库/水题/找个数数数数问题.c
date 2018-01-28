#include<stdio.h>
void Cha_two(int *s,int k,int l,int r)
{
    int i=l,j=r;
    int x1=-1,x2=-1,x3=-1,x4=-1;
    while(r>=l)//找到x2x4 的大致位置
    {
        if(s[l+(r-l)/2]==k)
        {
              x2=l+(r-l)/2+1;
              x4=l+(r-l)/2+1;
              break;
        }
       if(s[l+(r-l)/2]>k)
        {
            r=l+(r-l)/2-1;
           x2=l+(r-l)/2+1;
        }
        else if(s[l+(r-l)/2]<k)
        {
            l=l+(r-l)/2+1;
            x4=l+(r-l)/2+1;
        }
    }
    //找x2的最大位置,以及判断x2
    if(s[x2-1]>k) x2--;
    while(s[x2]==k) x2++;
    //找x4 的最小位置，以及判断x4
    if(s[x4-1]<k) x4++;
    while(s[x4-2]==k) x4--;
    //更具x2找x1的位置
    x1=x2; while(s[x1-1]==k) x1--; if(x1==0) x1=-1;
    //更具x4找x3的位置
    x3=x4; while(s[x3-1]==k) x3++; if(x3==j+2 ) x3=-1;

    printf("%d %d %d %d\n",x1,x2,x3,x4);
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
            Cha_two(Shu,x,0,N-1);
    }
}
