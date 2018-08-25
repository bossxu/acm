#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
vector<int>quan[10005];
ll a[20005];
ll que[20005];
ll sum[20005];
int vis[20005];
int main()
{
  int t;
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  scanf("%d",&t);
  int kase=0;
  while(t--)
  {
    int n,K;
    ll S,m;
    memset(vis,0,sizeof(vis));
    scanf("%d%lld%lld%d",&n,&S,&m,&K);
    for(int i=0;i<=n;i++)
    {
      quan[i].clear();
      quan[i].push_back(0);
    }
    for(int i = 0;i<n;i++)
    {
      scanf("%lld",&a[i]);
      a[i+n]=a[i];
    }
    int tot=0;
    ll tmp;
    for(int i = 0;i<n;i++)
    {
      int next = i;
      if(!vis[next])
        tot++;
      while(!vis[next])
      {
        vis[next] = 1;
        quan[tot].pb(next);
        next = (next+K)%n;
      }
    }
    ll fx=0;
    ll ans;
    ll s;
    int st,ed,head,tail;
    int k;
    for(int i=1;i<=tot;i++)
    {
      int p=m/(quan[i].size()-1);
      k=m%(quan[i].size()-1);
      ans=0;
      sum[0]=0;
      ll tmp;
      s=0;
      st=1,ed=1;
      for(int j=0;j<quan[i].size();j++)
      {
        s+=a[quan[i][j]];
        sum[j]=sum[j-1]+a[quan[i][j]];
        if(j<=k)
        {
          if(sum[j]>ans)
          {
            ans=sum[j];
            ed=j;
          }
        }
      }
      for(int j=0;j<quan[i].size();j++)
      {
        sum[j+n]=sum[j-1+n]+a[quan[i][j]];
        if((j+n)<=k)
        {
          if(sum[j+n]>ans)
          {
            ans=sum[j+n];
            ed=j+n;
          }
        }
      }
      head=tail=0;
      que[tail++]=1;
      for(int j=0;j<quan[i].size();j++)
      {
        while(head!=tail&&j-que[head]>k)
          ++head;
        while(head!=tail&&sum[j]<=sum[que[tail-1]])
        --tail;
        int flag=-1;
        if(j<=k&&sum[que[head]]>=0)
          tmp=sum[j],flag=1;
        else if(head==tail)
          tmp=a[quan[i][j]],flag=2;
        else
          tmp=sum[j]-sum[que[head]],flag=3;
        if(tmp>ans)
        {
          ans=tmp;
          if(flag==1) st=1;
          else if(flag==2) st=i;
          else st=que[head]+1;
          ed=i;
        }
        que[tail++]=i;
      }
      if(s>0)
        fx=max(fx,ans+1LL*p*s);
      else
        fx=max(fx,max(0LL,ans));
      if(p>0)
      {
        k=n+1;
        ans=0;
        sum[0]=0;
        ll tmp;
        s=0;
        st=1,ed=1;
        for(int j=0;j<quan[i].size();j++)
        {
          s+=a[quan[i][j]];
          sum[j]=sum[j-1]+a[quan[i][j]];
          if(j<=k)
          {
            if(sum[j]>ans)
            {
              ans=sum[j];
              ed=j;
            }
          }
        }
        for(int j=0;j<quan[i].size();j++)
        {
          sum[j+n]=sum[j-1+n]+a[quan[i][j]];
          if((j+n)<=k)
          {
            if(sum[j+n]>ans)
            {
              ans=sum[j+n];
              ed=j+n;
            }
          }
        }
        head=tail=0;
        que[tail++]=1;
        for(int j=0;j<quan[i].size();j++)
        {
          while(head!=tail&&j-que[head]>k)
            ++head;
          while(head!=tail&&sum[j]<=sum[que[tail-1]])
          --tail;
          int flag=-1;
          if(j<=k&&sum[que[head]]>=0)
            tmp=sum[j],flag=1;
          else if(head==tail)
            tmp=a[quan[i][j]],flag=2;
          else
            tmp=sum[j]-sum[que[head]],flag=3;
          if(tmp>ans)
          {
            ans=tmp;
            if(flag==1) st=1;
            else if(flag==2) st=i;
            else st=que[head]+1;
            ed=i;
          }
          que[tail++]=i;
        }
        if(s>0)
          fx=max(fx,ans+1LL*(p-1)*s);
        else
          fx=max(fx,max(0LL,ans));
      }
    }
    //cout<<fx<<endl;
    printf("Case #%d: %lld\n",++kase,max(0LL,S-fx));
  }
  return 0;
}
