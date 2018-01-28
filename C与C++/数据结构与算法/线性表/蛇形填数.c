#include<stdio.h>
#define max 10

int main()
{
    int n,i,j;
    printf("�����뷽��Ϊ���׷���");scanf("%d",&n);
    int item =0,shu[max][max],count;
    for(i=0,count=1;i<n;i++,count++) shu[i][n-1]=count;int a=n-1,b=n-1,k=0;
    count--;
    for(i=n-1;i>0;i--)
    {
      switch(item%4)
      {
         case 0:while(k!=i) {shu[a][--b]=++count;k++;} break;
         case 1:while(k!=i) {shu[--a][b]=++count;k++;} break;
         case 2:while(k!=i) {shu[a][++b]=++count;k++;} break;
         case 3:while(k!=i) {shu[++a][b]=++count;k++;} break;
      }
      k=0;item++;
       switch(item%4)
      {
         case 0:while(k!=i) {shu[a][--b]=++count;k++;} break;
         case 1:while(k!=i) {shu[--a][b]=++count;k++;} break;
         case 2:while(k!=i) {shu[a][++b]=++count;k++;} break;
         case 3:while(k!=i) {shu[++a][b]=++count;k++;} break;
      }
      k=0;item++;


    }

for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
        printf("%4d",shu[i][j]);
    putchar('\n');
    getchar();
}



    return 0;
}
