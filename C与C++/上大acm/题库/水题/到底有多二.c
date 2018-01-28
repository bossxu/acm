#include<stdio.h>
int main()
{
    int i,j,n,k,sun;
    scanf("%d",&n);
    int count=0;
    while(n!=count)
    {
        while(scanf("%d",&k)==1)
       {
        sun=0;
        for(i=2;i<=k;i+=2)
        {
            j=i;
            while(j%2==0)
            {
                j/=2;sun++;
            }
        }
        printf("%d\n",sun);
        count++;
        if(count==n) break;
       }
    }
    return 0;
}
