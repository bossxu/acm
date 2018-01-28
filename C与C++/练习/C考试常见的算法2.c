#include<stdio.h>
#include<math.h>
#include<string.h>
void sushu()//判断是不是素数
{
    printf("请输入要判断的数：");
    int j,i,shu;
    scanf("%d",&shu);
    for(i=2;i<shu;i++)
    {
        if(shu%i==0) {printf("这个数不是素数");return;}
    }
        printf("这个数是素数");
}
void huiwen()//判断是否回文
{
    printf("请输入要判断的字符串：\n提示：数字也可以是字符组，还有长度不要超过20\n");
    int min,max;
    char zifu[20];
    scanf("%s",zifu);
   for(min=0,max=strlen(zifu)-1;min<max;min++,max--)
   {
       if(zifu[min]!=zifu[max]) {printf("这个字符不是回文的");break;}
   }
      if(min>=max) printf("这个字符串是回文的");
}
void liangshu()//求两数的最大公因数和最大公倍数
{
    printf("请输入两个数：\n");
    int i,j,a[2];for(i=0;i<2;i++) {printf("请输入第%d个数：",i+1);scanf("%d",&a[i]);}
    for(i=fabs(a[0]-a[1]);i>1;i--)
    {
        if(a[0]%i==0&&a[1]%i==0) break;
    }
    if(i==0) printf("别瞎鸡吧输相等的数");
    else printf("这两个数的最大的公因数是：%d\n最小的公倍数是：%d\n",i,a[0]*a[1]/i);
}
void shuixian()//水仙花数的判定
{
    int a,b=0,n;
    printf("请输入要判定的数：\n");
    scanf("%d",&n);
    for(a=n;a!=0;a/=10) b=b+(a%10)*(a%10)*(a%10);
    if(b==n) printf("是水仙花数");
    else printf("不是水仙花数");
}
void zifutiao()//字符大小写的调节
{
    char zifu[20];
    printf("请输入要判断的字符串：\n提示：数字也可以是字符组，但不要有空格，还有长度不要超过20\n");
    scanf("%s",zifu);
    printf("请选择怎么调\n1：大写变小写\t2：小写变大写\t3：删个字符\n");
    int i,j,k;
    char c;
    scanf("%d",&k);

    switch(k)
    {
        case 1:printf("行，调好后长这样：\n");for(i=0;i<strlen(zifu);i++) {if(zifu[i]<='Z'&&zifu[i]>='A') printf("%c",zifu[i]+32); else printf("%c",zifu[i]);} break;
        case 2:printf("行，调好后长这样：\n");for(i=0;i<strlen(zifu);i++) {if(zifu[i]<='z'&&zifu[i]>='a') printf("%c",zifu[i]-32); else printf("%c",zifu[i]);} break;
        case 3:printf("请输入要删除的字符：\n");
        getchar();scanf("%c",&c);
        printf("行，调好后长这样：\n");
        for(i=0;i<strlen(zifu);i++)
            {
                if(zifu[i]==c) continue;
                else printf("%c",zifu[i]);
            } break;
    }

}
int main()
{
    printf("欢迎使用常见算法的小程序\n请选择要解决的问题：\n1:素数的判定\n2:回文字符串的判定\n3:求两数的最大公因数和最大公倍数\n4:水仙花数的判定\n5:字符大小写的判定\n0:退出程序\n");
    int i,j,k;
    while(1)
    {
        printf("请选择要解决的问题的序列：\n");
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

        printf("\n\n-----------------------------------这是分界线-------------------------------------------\n\n");
    }
  printf("谢谢使用；");
    return 0;
}
