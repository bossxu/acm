#include <stdio.h>
int main()
{
    // �����������i,j�Լ����result
    int i, j, result;
    /*
     * ʹ��forѭ�����������Լ�Ŷ~
     * С��͵͵�Ľ�Դ��������񡰲�������ô�족����Ŷ~
     * С��ϣ��ͯЬ�Ƕ������Ŷ~
     */

    for(i=9;i>0;i--)
    {
       for(j=1;j<=i;j++)
       {
           result=i*j;
           printf("%d*%d=%d",i,j,result);

       }
       printf("\n");
    }




    return 0;
}
