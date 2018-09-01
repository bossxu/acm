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
int shu[205][20];
int tot;
vector<int>que;
int n,m;
bool check(int st)
{
  int flag = 1;
  for(int i = 1;i<=13;i++)
  {
    if(shu[st][i] > 0) flag = 0;
  }
  return flag;
}
int slove()
{
  int st = 0;
  int be = 0;
  int last = -1;
  while(true)
  {
    //cout<<last<<" "<<be<<endl;
    if(last == -1)
    {
      int flag = 1;
      for(int i = 1 ;i<=13;i++)
      {
        if(shu[st][i] > 0)
        {
          shu[st][i]--;
          last = i;
          flag = 0;
          break;
        }
      }
      if(flag) return st;
      if(check(st)) return st;
      be = st;
      st = (st+1)%n;
    }
    else
    {
      if(be == st || last==13)
      {
        last = -1;
        for(int i = 0;i<n && tot<m;i++)
        {
          shu[(be+i)%n][que[tot++]]++;
        }
        st = be;
        continue;
      }
      else
      {
        if(shu[st][last+1] > 0)
        {
          shu[st][last+1]--;
          last = last+1;
          be = st;
          if(check(st))
          {
            return st;
          }
        }
        else  if(shu[st][13] > 0)
        {
          shu[st][13]--;
          last = 13;
          be = st;
          if(check(st))
          {
            return st;
          }
        }
          st = (st+1)%n;
      }
    }
  }
  return st;
}
int num[205];
int main()
{
  int t;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  int item = 0;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&m);
    que.clear();
    for(int i = 1;i<=m;i++)
    {
      int a;
      scanf("%d",&a);
      if(a == 1||a == 2) a = 11+a;
      else a-=2;
      que.pb(a);
    }
    tot = 0;
    clr(num,0);
    for(int i = 0;i<n && tot<m;i++)
    {
      clr(shu[i],0);
      for(int j = 1;j<=5 && tot<m;j++)
      {
        shu[i][que[tot++]]++;
      }
    }
    int end = slove();
    for(int i = 0;i<n;i++)
    {
      if(end == i) {num[i] = -1;continue;}
      for(int j = 1;j<=13;j++)
      {
        int val;
        if(j == 12 || j== 13) val = j-11;
        else val = j+2;
        num[i] += val*shu[i][j];
      }
    }
    printf("Case #%d:\n",++item);
    for(int i = 0;i<n;i++)
    {
      if(num[i] == -1)
      {
        printf("Winner\n");
      }
      else
      printf("%d\n",num[i]);
    }
  }
  return 0;
}
