#include<stdio.h>
int main()
{
char c[100],s[100],a;
int i=0,b,j;
while((c[i++]=getchar())!='\n');
b=i;
c[b]='\0';
scanf("%c",&a);
j=0;
for(i=0;i<b;i++){
 if(c[i]!=a) s[j++]=c[i];
}
s[j]='\0';
printf("%s",s);
return 0;

}
