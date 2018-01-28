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
struct st{
    char xue[6];
    char name[10];
    int num;
}node[100000];
int cmp_1(st a,st b)
{
   int s1=0,s2=0;
   for(int i=0;i<6;i++)
   {
       s1=s1*10+a.xue[i]-'0';
       s2=s2*10+b.xue[i]-'0';
   }
   if(s1<s2) return 1;
   else return 0;
}
int cmp_2(st a,st b)
{
    int s1=0,s2=0;
    if(strcmp(a.name , b.name)<0)
     return 1;
    if(strcmp(a.name , b.name)==0)
    {
         for(int i=0;i<6;i++)
   {
       s1=s1*10+a.xue[i]-'0';
       s2=s2*10+b.xue[i]-'0';
   }
       if(s1<s2) return 1;
    }
     return 0;
}
int cmp_3(st a, st b)
{
    int s1=0,s2=0;
    if(a.num<b.num)
    return 1;
    if(a.num==b.num) 
    {  for(int i=0;i<6;i++)
   {
       s1=s1*10+a.xue[i]-'0';
       s2=s2*10+b.xue[i]-'0';
   }
   if(s1<s2) return 1;
    }
     return 0;
}
int main()
{
    int n,c,ca=0;
    while(scanf("%d %d",&n,&c)==2)
    {
        if(n==0 ) break;
        for(int i=0;i<n;i++)
        {
            scanf("%s",node[i].xue);
            scanf("%s",node[i].name);
            scanf("%d",&node[i].num);
        }
        switch(c)
        {
            case 1:sort(node,node+n,cmp_1);break;
            case 2:sort(node,node+n,cmp_2);break;
            case 3:sort(node,node+n,cmp_3);break;
        }
        printf("Case %d:\n",++ca);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<6;j++) printf("%c",node[i].xue[j]);
            printf(" %s %d\n",node[i].name,node[i].num);
        }
    }
    return 0;
}