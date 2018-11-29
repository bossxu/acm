#include<bits/stdc++.h>
#define ll long long
#define mkr make_pair
using namespace std;
const int maxnode=75e5;
int ff;
vector<int>tmp;
vector< pair<ll,int> > ans;

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
    int flag=0;
    if(buf[0]=='+')
     flag=1;
     ll x=0;ll now=0;
     int range=32;
     for(int i=1;i<len;i++)
     {
       if(buf[i]=='/')
       {
         range=0;
         x=(x<<8)+now;
         for(int j=i+1;j<len;j++)
           range=range*10+buf[j]-'0';
           break;
       }
       else if(buf[i]=='.')
       {
         x=(x<<8)+now;
         now=0;
         continue;
       }
       else now=now*10+buf[i]-'0';
     }
     // cout<<x<<endl;
      now=0;
     for(int i=31;i>=32-range;i--)
     {
        ed[now]|=1<<flag;
       int id=(x>>i)&1;
       if(next[now][id]==-1)
          next[now][id]=newnode();
       now=next[now][id];
     }
     ed[now]|=1<<flag;
     tmp.push_back(now);
    for(int i=0;i<tmp.size();i++)
     if(ed[tmp[i]]==3)
      ff=1;
  }
  void dfs(int now,int l,ll mask)
  {
    if((ed[now]&1)==0) return;
    if(ed[now]==1)
    {
      ans.push_back(mkr(mask,32-l));
      return;
    }
    l--;
    if(l<0) return ;
    for(int i=0;i<2;i++)
    {
      if(next[now][i]!=-1)
       dfs(next[now][i],l,mask^((ll)i<<l));
    }
  }

}ac;
void prin(pair<ll,int> p)
{
  ll mask=p.first;
  printf("%lld.%lld.%lld.%lld/%d\n",(mask>>24)&255,(mask>>16)&255,(mask>>8)&255,mask&255,p.second);
}

char s[maxnode];
int main()
{
  int n;
  while(scanf("%d",&n)==1)
  {
    ans.clear();
    tmp.clear();
    ac.init();
    for(int i=1;i<=n;i++)
    {
      scanf("%s",s);
      ac.insert(s);
    }
      if(ff==1)
      {
        printf("No\n");
      }
      else
      {
        ac.dfs(0,32,0);
       printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
         prin(ans[i]);
      }
    }

}
