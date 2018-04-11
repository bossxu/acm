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
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
//字符串板子题
const int maxnode = 1000100,sigma_size = 26;
int ch[maxnode][sigma_size];
int val[maxnode];
int sz;
inline int idx(char c) { return c-'a'; }
void init()
{
  clr(ch[0],0);
  clr(val,0);
  sz = 1;
}
void insert(char *s)
{
    int u=0, n=strlen(s);
    for (int i=0; i<n; i++)
    {
        int c=idx(s[i]);
        if (ch[u][c]==0) //empty
        {
            clr(ch[sz],0);
            //val[sz]=0; //not a word
            ch[u][c]=sz++;
        }
        u=ch[u][c];
        val[u]++;
    }
}
int search(char *s)
{
    int u=0, n=strlen(s);
    for (int i=0; i<n; i++)
    {
        int c=idx(s[i]);
        if (ch[u][c]==0)
            return 0;
        u=ch[u][c];
    }
    return val[u];
}
int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   char s[20];
   init();
   while(gets(s))
   {
    if(s[0] == NULL) break;
     //cout<<s<<endl;
     insert(s);
   }
   while(gets(s))
   {
     //cout<<s<<endl;
     printf("%d\n",search(s));
   }
   //cout<<"hello"<<endl;
  return 0;
}
