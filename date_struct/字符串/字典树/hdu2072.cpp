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
const int maxnode = 1000100,sigma_size = 26;
int trie[maxnode][sigma_size];
int val[maxnode];//这里最简单的意义在于记录那个点是否是单词结尾节点。
int sz,flag,num;
inline int idx(char c) { return c-'a'; }
void init()
{
  clr(trie[0],0);
  clr(val,0);
  sz = 1;
  flag = 0;
  num = 0;
}
void insert(char *s,int item)
{
    int u=0, n=item;
    for (int i=0; i<n; i++)
    {
        int c=idx(s[i]);
        if (trie[u][c]==0) //empty
        {
            clr(trie[sz],0);
            trie[u][c]=sz++;
        }
        u=trie[u][c];
    }
    if(!val[u]) num++;
    val[u] = 1;
}
int main()
{
   char s[10000];
   while(gets(s))
   {
     //cout<<s<<endl;
     init();
     if(s[0] == '#') break;
     char op[20];
     int item = 0;
     //cout<<strlen(s)<<endl;
     for(int i = 0;i<strlen(s);i++)
     {
       if(s[i]==' ')
       {
         if(item > 0)
         {
           insert(op,item);
           item = 0;
         }
       }
       else
       {
         op[item++] = s[i];
       }
     }
     if(item > 0) insert(op,item);
     //cout<<item<<endl;
     cout<<num<<endl;
   }
  return 0;
}
