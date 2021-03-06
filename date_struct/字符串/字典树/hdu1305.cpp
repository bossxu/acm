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
const int maxnode = 1000100,sigma_size = 2;
int trie[maxnode][sigma_size];
int val[maxnode];//这里最简单的意义在于记录那个点是否是单词结尾节点。
int sz;
inline int idx(char c) { return c-'0'; }
int flag = 0;
void init()
{
  clr(trie[0],0);
  clr(val,0);
  sz = 1;
  flag = 0;
}
void insert(char *s)
{
    int u=0, n=strlen(s);
    for (int i=0; i<n; i++)
    {
        int c=idx(s[i]);
        if (trie[u][c]==0) //empty
        {
            clr(trie[sz],0);
            if(val[u]) flag = -1; //not a word
            trie[u][c]=sz++;
        }
        u=trie[u][c];
    }
    if(val[u] == 1) flag = -1;
    val[u] = 1;
}
int main()
{
  //freopen("in.txt","r",stdin);
  char s[100];
  flag = 0;
  int item = 0;
  init();
  while(gets(s))
  {
    if(s[0] == '9')
    {
      if(flag == -1)
      {
        printf("Set %d is not immediately decodable\n",++item);
      }
      else
      {
        printf("Set %d is immediately decodable\n",++item);
      }
      init();
    }
    else
    {
      insert(s);
    }
  }
  return 0;
}
