#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
int n;
const int maxn=20005;
const double eps = 1e-6;
bool judge(char c)
{
  if(c<='9' && c>='0')
  return true;
  else
  return false;
}
int main()
{
  int t;
  char c[1005];
  char cun[1005];
  cin>>t;
  getchar();
  while(t--)
  {
    gets(c);
    int k=0,o=0,l=0;
    for(int i=0;i<strlen(c);i++)
    {
      if(c[i]!=' ')
      cun[k++]=c[i];
      if(c[i]=='.') o++;
      if(c[i]=='e' || c[i]=='E')
      l++;
    }
    int item = 1,ap=0;
    if(o>1 || l>1) item =0;
    for(int i=0;i<k;i++)
    {
      if(cun[i]=='.')//有点
      {
        if(i==0 || i==k-1 || ap)
         item = 0;
        else
        {
          if(!judge(cun[i-1]) || !judge(cun[i+1]))
           item = 0;
        }
      }
      else if(cun[i]=='E' || cun[i]=='e')//e的情况
      {
        ap=1;
        if(i==0 ||i==k-1||!judge(cun[i-1]) || !(judge(cun[i+1]) ||cun[i+1]=='+'||cun[i+1]=='-'))
         item =0;
      }
     else if(cun[i]=='+' || cun[i]=='-')//尾巴有加减的情况
      {
        if(i==k-1) item=0;
        if(i!=0 && !(cun[i-1]=='e' || cun[i-1]=='E')) item =0;
      }
      else if(!judge(cun[i]))//有字母的情况
       item=0;
    }
    if(item ) printf("LEGAL\n");
    else printf("ILLEGAL\n");
  }
  return 0;
}
