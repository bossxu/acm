#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define mod 13
int pan(char *a)
{
    int i,j,sum;
    sum=a[0]-'0';
    for(i=1;a[i]!='\0';i++)
    {
        sum=10*sum+a[i]-'0';
        sum=sum%mod;
    }
    if(sum==0) return 1;
    else return 0;
}
int main()
{
    int i,j,t;
    cin>>t;getchar();
    char a[85];
    while(t--)
    {
          gets(a);
          if(pan(a)) printf("Yes\n");
          else printf("No\n");
    }
    return 0;
}
