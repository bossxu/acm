#include<stdio.h>
void pai_1(int a[],int n)//ð������
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j]) //��С������
            {
                t=a[i];a[i]=a[j];a[j]=t;
            }
        }
    }
}
void pai_2(int a[],int n)//ѡ������
{
    int i,j,k,min;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)//��С����
        {
          if(a[j]<a[min]) min=j;
        }
        k=a[i];a[i]=a[min];a[min]=k;
    }
}
void pai_3(int a[],int n)//��������
{
    int i,j,k;
    for(i=0;i<n;i++)
        {
            for(j=i;j!=0;j--)
        {
            if(a[j]<a[j-1])
                {
                     k=a[j-1];a[j-1]=a[j];a[j]=k;
                }
        }
        }
}
void show(int a[],int n)
{
    int i;
    for(i=0;i<n;i++) printf("%2d",a[i]);
}
void cha_1(int a[],int n,int shu)//���ַ������죬Ҫ��д��
{
    int i,j,mid,min,max;
    max=n-1;min=0;
    while (max>min)
    {
        mid=(max+min)/2;
        if(a[mid]==shu) break;
        if(a[mid]<shu) min=mid+1;
        else  max=min-1;
    }
    if(max<=min) printf("Ϲ����������\n");
    else  printf("�����������ĵ�%d����",mid+1);

}
void cha_2(int a[],int n,int shu)//������ҷ�
{
   int i;
   for(i=0;i<n;i++)
   {
       if(shu==a[i]) {printf("�����������ĵ�%d����",i+1);return;}
   }
   printf("Ϲ����������\n");
}
int main()
{
    int a[6]={5,8,1,2,3,9},n,it,shu;
    show(a,6);
    printf("\n������ԭʼ���������\n");
    printf("��ѡ��Ҫ����ķ�ʽ��\n1:ð������\t2:ѡ������\t3:��������\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:pai_1(a,6);break;
        case 2:pai_2(a,6);break;
        case 3:pai_3(a,6);break;
    }

    printf("�����Ѿ���������ѡ��ʣ��Ҫ�����£�");
    while(1)
    {
        printf("\n�������¼���ѡ��\n1:չʾ�źõ�����\t2������\t3����0�˳�ϵͳ\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: show(a,6);break;
            case 2:printf("���ҵķ��������¼���������\n1�����ַ���\t2���������\t3����Ҫ�ǰ����˾Ͱ�0�˳�\n");
                    scanf("%d",&it);
                    if(it==0) break;
                    printf("������Ҫ�ҵ�����");scanf("%d",&shu);
                    switch(it)
                    {
                        case 1:cha_1(a,6,shu);break;
                        case 2:cha_2(a,6,shu);break;
                    }
        }
         if(n==0) {printf("\n��лʹ�ø�ϰ���������\n�ټ�");break;}
    }
    return 0;
}
