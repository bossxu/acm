#include<stdio.h>
#include<string.h>
int main()
{
    int t[100],i,k=0,j,m;
    char str[1005];
    while(gets(str)!=NULL){
      for(int i = 0;i<26;i++)
      {
        t[i] = 0;
      }
      for(i=0;i<strlen(str);i++)
        if((str[i]>='a' && str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
        {
            t[str[i]-'a']++;
            t[str[i]-'A']++;
        }
        printf("Case %d: ",++k);
        for(i=0;i<25;i++)
        printf("%d ",t[i]);
        printf("%d\n",t[25]);
    }
    return 0;

}
