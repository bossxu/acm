#include<stdio.h>
int main()
{
    int arr[]={10,11,12,13,14,12,15,19,11,14};
    int i,j,temp;
    for(i=9;i>=0;i--)
    {
        for(j=0;j<=i;j++)                   //���ģ�ת��˳�򣬸ı�����������ֵ���������һ�
        {
            if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                }
        }
    }
        for(i=0;i<=9;i++)
        {
            printf("%d ",arr[i]);
        }


        return 0;
    }


