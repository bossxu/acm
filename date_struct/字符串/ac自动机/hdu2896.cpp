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
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int shu[3];
int item;
struct Trie
{
    int next[100010][130],fail[100010],end[100010];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 130;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[],int val)
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            int k = buf[i];
            if(next[now][k] == -1)
                next[now][k] = newnode();
            now = next[now][k];
        }
        end[now] = val;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 128;i++)
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
            for(int i = 0;i < 128;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        int flag = 0;
        item = 0;
        for(int i = 0;i < len && item < 3;i++)
        {
            int k = buf[i];
            now = next[now][k];
            int temp = now;
            while( temp != root )
            {
                flag = 0;
                if(end[temp])
              {
                for(int i = 0;i<item;i++)
                {
                  if(shu[i] == end[temp])
                  {
                    flag = 1;
                  }
                }
                if(!flag && item<3)
                shu[item++]= end[temp];
              }
                temp = fail[temp];//向上归根
            }
        }
    }
}AC;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  char s[10005];
  int n,t;
  int num = 0,lala=0;
  cin>>n;getchar();
  AC.init();
  for(int i = 1;i<=n;i++)
  {
    gets(s);
    AC.insert(s,++num);
  }
  cin>>t;getchar();
  AC.build();
  //cout<<"hello"<<endl;
  for(int i = 1;i<=t;i++)
  {
    gets(s);
    AC.query(s);
    if(item){
    printf("web %d:",i);
    lala++;
    sort(shu,shu+item);
    for(int j = 0;j<item;j++)
    {
      printf(" %d",shu[j]);
    }
    cout<<endl;
  }
  }
  printf("total: %d\n",lala);


  return 0;
}
