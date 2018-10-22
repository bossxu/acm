//langman
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
const int N = 2e5+10;
struct node
{
  int x,y;
}Q[N];
int n;
bool cmp(node a,node b)
{
  if(a.x == b.x) return a.y<b.y;
  return a.x<b.x;
}
priority_queue<int,vector<int>,greater<int> >q;
int tree[200000+10];
int lowbit(int t)
{
  return t&(-t);
}
void add(int x,int y)
{
  for(int i=x;i<=200000;i+=lowbit(i))
  tree[i]+=y;
}
int getsum(int x)
{
  int ans=0;
  for(int i=x;i>0;i-=lowbit(i))
    ans+=tree[i];
  return ans;
}
void add0(int x,int y)
{
  for(int i = x;i>0;i-=lowbit(i))
  {
    tree[i] += y;
  }
}
int getsum0(int x)
{
  int ans = 0;
  for(int i = x;i<=200000;i+=lowbit(i))
  {
    ans += tree[i];
  }
  return ans;
}
int shu[N];
int cal()
{
  clr(tree,0);
  clr(shu,0);
  for(int i = n;i>=1;i--)
  {
    shu[i] += getsum(Q[i].y-1);
    add(Q[i].x,1);
  }
  clr(tree,0);
  for(int i = 1;i<=n;i++)
  {
    shu[i] += getsum0(Q[i].x+1);
    add0(Q[i].y,1);
  }
  int ans = 0;
  for(int i = 1;i<=n;i++)
  {
    ans = max(ans,shu[i]);
  }
  return ans;
}
int slove()
{
  while(!q.empty()) q.pop();
  for(int i = 1;i<=n;i++)
  {
    if(q.empty())
      {
        q.push(Q[i].y);
        continue;
      }
    else
      {
        if(q.top() <= Q[i].x)
        {
          q.pop();
          q.push(Q[i].y);
        }
        else
        {
          q.push(Q[i].y);
        }
      }
  }
  return q.size();
}
int main()
{
  ios_close;
  while(cin >> n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin >> Q[i].x >> Q[i].y;
    }
    sort(Q+1,Q+n+1,cmp);
    int ans2 = slove();
    int ans1 = cal()+1;
    cout<<ans1<<" "<<ans2<<endl;
  }
  return 0;
}
