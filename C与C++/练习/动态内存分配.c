#include<stdio.h>
#include<stdlib.h>
int main()
{
    int sum,n,i,*p;
    printf("please input the number");
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));//ռ�������ڴ�Ĵ�С��
    if(p==NULL){//��������Ϊʲô
        printf("there is no money");
        return -1;
    }
    printf("please input %d number",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",p+i);
    }
    sum=0;
    for(i=0;i<5;i++)
    {
        sum=sum+*(p+i);
    }
    printf("the sum is %d",sum);
    free(p);//�ͷ��ڴ�

    return 0;
}
