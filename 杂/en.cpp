#include<bits/stdc++.h>
using namespace std;
int ff;
struct trie
{
  int next[maxnode][2],fail[maxnode],ed[maxnode];
  int root,cnt;
  int newnode()
  {
    for(int i=0;i<2;i++)
     next[cnt][i]=-1;
     ed[cnt++]=0;
     return cnt-1;
  }
  void init()
  {
    ff=0;
    cnt=0;root=newnode();
  }
  void insert(char *buf)
  {
    int len=strlen(buf);
    int flag=1;
    if(buf[0]=='+')
     flag=-1;
     ll x=0;ll now=0;
     ll range=-1;
     for(int i=0;i<len;i++)
     {
       if(s[i]=='/')
       {
         range=0;
         for(int j=i+1;j<len;j++)
           range=range*10+s[j]-'0';
           break;
       }
       else if(s[i]=='.')
       {
         x=x*1000+now;
         now=0;
         continue;
       }
       else now=now*10+s[i]-'0';
     }

     for(int i=31;i>=0;i--)
     {
       int id=(x>>i)&1;
       if(next[now][id]==-1)
          next[now][id]=newnode();

       now=next[now][id];
     if(range!=-1&&i<=32-range&&id==0)
      {
       next[now][1]=newnode();
    if(ed[next[now][1]]==0||ed[[now][1]]==flag)
        ed[next[now][1]]=flag;//must include
      else ff=1;
      }
     }
     if(ed[now]==0||ed[now]==flag)
     ed[now]=flag;
     else ff=1;

    }
    void build()
    {
      queue<int>que;
      fail[root]=root;
      for(int i=0;i<2;i++)
      {
        if(next[root][i]==-1)
         next[root][i]=root;
         else
         {
           fail[next[root][i]]=root;
           que.push(next[root][i]);
         }
      }
      while(!que.empty())
      {
        int now=que.front();
        que.pop();
        for(int i=0;i<2;i++)
        {
          if(next[now][i]==-1)
           next[now][i]=next[fail[now]][i];
           else
           {
             fail[next[now][i]]=next[fail[now]][i];
             if(ed[now])
             {
               if(ed[next[now][i]]&&ed[next[now][i]]!=ed[now])
                 ff=1;
                 else ed[next[now][i]]=ed[now];
             }
             que.push(next[now][i]);
           }
        }
      }
    }
    int dfs(int pos)
    {
     if(ed[pos]==-1) return -1;// bu ke xing
     int x=0;
     if(next[pos][1])
       x=dfs(next[pos][1]);
     int y=0;
    if(next[pos][0])
       y=dfs(next[pos][0]);
     if(x==-1||y==-1) return -1;
     if(ed[pos]==1)
     {
       vec.push(pos);
       return 1;
     }
     return x+y;
    }
    int query()
    {
      if(ff) return -1;
      return dfs(root);
    }
}ac;
int main()
{
  int n;
  while(scanf("%d",&n)==1)
  {
    ac.init();
    for(int i=1;i<=n;i++)
    {
      scanf("%s",s);
      ac.insert(s);
    }
    ac.build();
    int x=ac.query();
     if(x==-1) printf("-1\n");
     else
     {
       printf("%d\n",asn);
     }

  }
}
