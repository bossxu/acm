#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

int main()
{
    char c;
    ll a[1500];
    int i;
    char s[1500];
    while(scanf("%s",s)!=EOF)
    {
      memset(a,0,sizeof(a));
     i=0;
      for(int k=0;k<strlen(s);k++)
      {
       if(k==0 && s[k]=='5') i--;
       if(s[k]=='5') 
        {
            while(s[k]=='5' && k < strlen (s)) k++;
            if(k>=strlen(s)) break;
            i+=1;
        } 
        a[i]=a[i]*10+s[k]-'0';
      }
      sort(a,a+i+1);
      if(i==-1) i++;
      for(int j=0;j<i;j++)
      {
         printf("%lld ",a[j]);
      }
      printf("%lld\n",a[i]);
    }
   return 0;
}