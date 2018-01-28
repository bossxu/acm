#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
#define maxsize 10005
int main()
{
    int i,j,k,t;
    cin>>t;getchar();
    char a[maxsize];
    int b[256];
    memset(b,0,sizeof(b));
    while(t--)
    {
        gets(a);
        for(i=0;i<strlen(a);i++)
        {
            b[a[i]]++;
        }
        for(i=0;i<strlen(a);i++)
        {
            if(b[a[i]]==1) break;
        }
        if(b[a[i]]==1) printf("%c\n",a[i]);
        else printf("*\n");
    }
    return 0;
}
