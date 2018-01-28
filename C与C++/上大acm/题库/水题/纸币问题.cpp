#include<cstdio>
#include<algorithm>
using namespace std;
int pan(int *a)
{
    int i=0;
    for(;*(a+i)<2;i++)
    {
         if(*(a+i)==1)
            return 0;
    }
        return 1;
}
int main()
{
    int n,i,j,k;
    int a[1005];
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
       if(pan(a)) printf("1\n");
       else
       {
           int sum=a[0];
           for(i=1;i<n;i++)
           {
               if(sum+1<a[i]) break;
               else sum+=a[i];
           }
           printf("%d",sum+1);
       }
    }
    return 0;
}

