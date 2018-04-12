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
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#include<cctype>
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int vis[1005];
struct Trie
{
    int next[50005][26],fail[50005],end[50005];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 26;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[],int z)
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'A'] == -1)
                next[now][buf[i]-'A'] = newnode();
            now = next[now][buf[i]-'A'];
        }
        end[now] = z;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 26;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() )
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 26;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    void query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i = 0;i < len;i++)
        {
            if(buf[i]>'Z' || buf[i]<'A')
            { now = root; continue;}
            now = next[now][buf[i]-'A'];
            //cout<<now<<endl;
            int temp = now;
            while( temp != root )
            {
                if(end[temp] > 0)
                {
                  vis[end[temp]]++;
                }
                temp = fail[temp];//向上归根
            }
        }
    }
}AC;
char s[1005][60];
char s2[2000005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n;
  while(cin>>n)
{  //getchar();
  AC.init();
  clr(vis,0);
  for(int i = 1;i<=n;i++)
  {
    scanf("%s",s[i]);
    //cout<<s[i]<<endl;
    AC.insert(s[i],i);
  }
  getchar();
  gets(s2);
  AC.build();
  AC.query(s2);
  for(int i = 1;i<=n;i++)
  {
    if(vis[i])
    {
      printf("%s: %d\n",s[i],vis[i]);
    }
  }
}
  return 0;
}
