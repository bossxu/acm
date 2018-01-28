#include<stdio.h>
int getscore(int arr[5],int a)
{
    int i;
    for(i=0;i<=4;i++)
    {
        if(arr[i]==a)
              return i;

    }
return -1;

}

int main()
{
int a,j ;
scanf("%d",&a);
int arr[5]={5,6,7,88,9};
    j= getscore(arr,a);
if  (j!=-1)
    printf("%d",j);
else
    printf("no");

    return 0;
}
