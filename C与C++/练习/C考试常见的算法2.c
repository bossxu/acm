#include<stdio.h>
#include<math.h>
#include<string.h>
void sushu()//�ж��ǲ�������
{
    printf("������Ҫ�жϵ�����");
    int j,i,shu;
    scanf("%d",&shu);
    for(i=2;i<shu;i++)
    {
        if(shu%i==0) {printf("�������������");return;}
    }
        printf("�����������");
}
void huiwen()//�ж��Ƿ����
{
    printf("������Ҫ�жϵ��ַ�����\n��ʾ������Ҳ�������ַ��飬���г��Ȳ�Ҫ����20\n");
    int min,max;
    char zifu[20];
    scanf("%s",zifu);
   for(min=0,max=strlen(zifu)-1;min<max;min++,max--)
   {
       if(zifu[min]!=zifu[max]) {printf("����ַ����ǻ��ĵ�");break;}
   }
      if(min>=max) printf("����ַ����ǻ��ĵ�");
}
void liangshu()//�������������������󹫱���
{
    printf("��������������\n");
    int i,j,a[2];for(i=0;i<2;i++) {printf("�������%d������",i+1);scanf("%d",&a[i]);}
    for(i=fabs(a[0]-a[1]);i>1;i--)
    {
        if(a[0]%i==0&&a[1]%i==0) break;
    }
    if(i==0) printf("��Ϲ��������ȵ���");
    else printf("�������������Ĺ������ǣ�%d\n��С�Ĺ������ǣ�%d\n",i,a[0]*a[1]/i);
}
void shuixian()//ˮ�ɻ������ж�
{
    int a,b=0,n;
    printf("������Ҫ�ж�������\n");
    scanf("%d",&n);
    for(a=n;a!=0;a/=10) b=b+(a%10)*(a%10)*(a%10);
    if(b==n) printf("��ˮ�ɻ���");
    else printf("����ˮ�ɻ���");
}
void zifutiao()//�ַ���Сд�ĵ���
{
    char zifu[20];
    printf("������Ҫ�жϵ��ַ�����\n��ʾ������Ҳ�������ַ��飬����Ҫ�пո񣬻��г��Ȳ�Ҫ����20\n");
    scanf("%s",zifu);
    printf("��ѡ����ô��\n1����д��Сд\t2��Сд���д\t3��ɾ���ַ�\n");
    int i,j,k;
    char c;
    scanf("%d",&k);

    switch(k)
    {
        case 1:printf("�У����ú�������\n");for(i=0;i<strlen(zifu);i++) {if(zifu[i]<='Z'&&zifu[i]>='A') printf("%c",zifu[i]+32); else printf("%c",zifu[i]);} break;
        case 2:printf("�У����ú�������\n");for(i=0;i<strlen(zifu);i++) {if(zifu[i]<='z'&&zifu[i]>='a') printf("%c",zifu[i]-32); else printf("%c",zifu[i]);} break;
        case 3:printf("������Ҫɾ�����ַ���\n");
        getchar();scanf("%c",&c);
        printf("�У����ú�������\n");
        for(i=0;i<strlen(zifu);i++)
            {
                if(zifu[i]==c) continue;
                else printf("%c",zifu[i]);
            } break;
    }

}
int main()
{
    printf("��ӭʹ�ó����㷨��С����\n��ѡ��Ҫ��������⣺\n1:�������ж�\n2:�����ַ������ж�\n3:�������������������󹫱���\n4:ˮ�ɻ������ж�\n5:�ַ���Сд���ж�\n0:�˳�����\n");
    int i,j,k;
    while(1)
    {
        printf("��ѡ��Ҫ�������������У�\n");
        scanf("%d",&k);
        switch(k)
        {
            case 1:sushu();break;
            case 2:huiwen();break;
            case 3:liangshu();break;
            case 4:shuixian();break;
            case 5:zifutiao();break;
        }
        if(k==0) break;

        printf("\n\n-----------------------------------���Ƿֽ���-------------------------------------------\n\n");
    }
  printf("ллʹ�ã�");
    return 0;
}
