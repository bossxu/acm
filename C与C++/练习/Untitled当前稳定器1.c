#include <stdio.h>

void print(int arr[2][2])
{
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    //ʹ�õ�һ�ַ�ʽ��ʼ����ʽ��������ʼ����ά����arr1
    int arr1[2][2]={{10,20},{30,40}};
    print(arr1);

    printf("*****\n");

    //ʹ�õڶ��ַ�ʽ��ʼ����ʽ��������ʼ����ά����arr2
    int arr2[2][2];
    arr2[0][0]=10;
    arr2[0][1]=20;
    arr2[1][0]=30;
    arr2[1][1]=40;
    print(arr2);
    return 0;
}
