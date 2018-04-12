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
const int maxnode = 1000100,sigma_size = 10;
int trie[maxnode][sigma_size];
int val[maxnode];//这里最简单的意义在于记录那个点是否是单词结尾节点。
int sz,flag;
inline int idx(char c) { return c-'0'; }
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
    int l = 0;
    for (int i=0; i<n; i++)
    {
        int c=idx(s[i]);
        if (trie[u][c]==0) //empty
        {
            clr(trie[sz],0);
            trie[u][c]=sz++;
            l++;
        }
        u=trie[u][c];
        if(val[u]) flag = -1;
    }
    if(!l) flag = -1;
    val[u] = 1;
}
int main()
{
  int t,n;
  cin>>t;
  char s[20];
  while(t--)
  {
    init();
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
      scanf("%s",s);
      //cout<<s<<endl;
      insert(s);
    }
    if(flag == -1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

  }
  return 0;
}
