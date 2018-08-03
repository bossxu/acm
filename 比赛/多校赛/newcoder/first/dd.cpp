#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*void dfs(int x,ll vis)
{
   for(int i=1;i<=n;i++)
   {
     for(int j=0;j<g1[x].size();j++)
     {
         g3[i].push_back(dfs(g1[x][j],vis|(1<<i)));

     }
   }

}*/
int cnt;
int n;
int a[20];
vector<int>g1[10];
vector<int>g2[10];
map<ll,int>mp;
typedef pair<int,int> P;
map<P,int>id;
void init()
{
  for(int i=0;i<=8;i++)
  {
    g1[i].clear();
    g2[i].clear();
  }
  cnt=0;
  mp.clear();
  id.clear();
}

int  check()
{
  ll edge=0;
   for(int i=1;i<=n;i++)
   {
     int t=a[i];
     for(int j=0;j<g1[t].size();j++)
     {
       int flag=0;
       int x=g1[t][j];
       for(int k=0;k<g2[i].size();k++)
       {
         if(x==a[g2[i][k]]) {
           int u=i;int v=g2[i][k];
           if(u>v) swap(u,v);
           flag=1;edge|=(1<<id[make_pair(u,v)]);break;
         }
       }
       if(flag==0) return 0;
     }
   }

  mp[edge]=1;
  return 1;
}

void dfs(int x,ll vis)
{
  if(x==n+1)
  {
  //  for(int i=1;i<=n;i++)
  //   cout<<a[i]<<" ";
  //   cout<<endl;
    check();
    return;
  }
   for(int i=1;i<=n;i++)
   {
     if(vis&(1<<i)) continue;
     a[x]=i;
     dfs(x+1,vis|(1<<i));
   }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int m1,m2;
  while(cin>>n>>m1>>m2)
  {
    init();
     for(int i=1;i<=m1;i++)
     {
       int a,b;
       cin>>a>>b;
       g1[a].push_back(b);
       g1[b].push_back(a);
     }

     for(int i=0;i<m2;i++)
     {
       int a,b;
       cin>>a>>b;
       g2[a].push_back(b);
       g2[b].push_back(a);
       if(a>b) swap(a,b);
       id[make_pair(a,b)]=i;
     }
     dfs(1,0);
     //dfs1(int i,ll vis);
     cout<<mp.size()<<endl;
  }
return 0;

}
