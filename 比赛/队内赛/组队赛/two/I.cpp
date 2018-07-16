#include<bits/stdc++.h>
using namespace std;
const int maxn=500+10;
int fa[maxn][maxn];
int G[maxn][maxn];
int dis[maxn][maxn];
int N,index;
int road[maxn][maxn];
int path[maxn];
map<string,int> m;
string s[maxn];
string tmp;
int vis[maxn];
void print(int id)
{
    if(vis[id])
        return ;
    vis[id]=1;
    print(fa[id]);
    cout<<s[id]<<" ";
}
void Record(int s,int t)
{
  if(road[s][t])
  {
    Record(s,road[s][t]);
    Record(road[s][t],t);
  }
  else
  {
    path[index++]=t;
  }
}
int ans;
void floyd()
{
  ans=0x3f3f3f3f;
  for(int k=1;k<=N;k++)
  {
    for(int i=1;i<k;i++)
    {
      for(int j=i+1;j<k;j++)
      {
        if(G[i][j]+dis[i][k]+dis[k][j]<ans)
        {
          ans=G[i][j]+dis[i][k]+dis[k][j];
          index=0;
          path[index++]=i;
          Record(i,j);
          path[index++]=k;
        }
      }
    }
    for(int i=1;i<=N;i++)
    {
      for(int j=1;j<=N;j++)
      {
        if(G[i][k]+G[k][j]<G[i][j])
        {
          G[i][j]=G[i][k]+G[k][j];
          road[i][j]=k;
        }
      }
    }
  }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>N)
    {
        for(int i=0;i<maxn;i++)
        {
            for(int j=0;j<maxn;j++)
            {
                G[i][j]=0x3f3f3f3f;
            }
        }
        memset(fa,0,sizeof(fa));
        m.clear();
        //cout<<111<<endl;
        for(int i=1;i<=N;i++)
        {
            cin>>s[i];
            m[s[i]]=i;
        }
        for(int i=1;i<=N;i++)
        {
            int x;
           cin>>tmp>>x;
           while(x--)
           {
               cin>>tmp;
               cin>>tmp;
               for(;;)
               {
                   int k=tmp.size();
                   if(tmp[k-1]!=',')
                   {
                       G[i][m[tmp]]=1;
                       break;
                   }
                   else
                   {
                       string t(tmp,0,k-1);
                       G[i][m[t]]=1;
                       //cout<<t<<endl;
                       cin>>tmp;
                   }
               }
           }
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dis[i][j] = G[i][j];
            }
        }
        floyd();
        if(ans==0x3f3f3f3f)
        {
          cout<<"SHIP IT"<<endl;
        }
        else
        {
          for(int i=0;i<index-1;i++)
          {
            cout<<s[path[i]]<<" ";
          }
          couit<<s[path[index-1]]<<endl;
        }
    }
    return 0;
}
