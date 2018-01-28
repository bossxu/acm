#include<stdio.h>
#include<string.h>
int main()
{
    char str1[30],str2[30],str3[30],*pc,*pa,*pb;
    printf("Enter 3 strings:\n");
    gets(str1);gets(str2);gets(str3);
    pa=str1;pb=str2;pc=str3;
    printf("The largest string is ");
    if(strcmp(pa,pb)>0)
    {
        if(strcmp(pa,pc)>0) puts(pa);
         else puts(pc);
    }
    else
    {
    if(strcmp(pb,pc)>0)    puts(pb);
    else puts(pc);
    }
    return 0;
}
