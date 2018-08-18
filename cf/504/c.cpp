#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
struct node
{
  char s;
  int id;
  int mix;
}Q[200005];
int vis[200005];
string op;
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,k;
  while(cin>>n>>k)
  {
    cin>>op;
    clr(vis,0);
    for(int i = 1;i<=n;i++)
    {
    //  cout<<op[i-1]<<endl;
      Q[i].s = op[i-1];
      Q[i].id = i;
    }
    stack<int>q;
    for(int i = 1;i<=n;i++)
    {
      if(q.empty() || Q[i].s == '(')
      {
        q.push(i);
      }
      else
      {
        if(Q[i].s == ')' && Q[q.top()].s=='(')
        {
          //cout<<"hello"<<endl;
          Q[i].mix = q.top();
          Q[q.top()].mix = i;
          q.pop();
        }
        else
        q.push(i);
      }
    }
    int tot = 0;
    for(int i = 1;i<=n;i++)
    {
    //  cout<<Q[i].mix<<endl;
      if(tot == k) break;
      if(Q[i].s == '(')
      {
        vis[i] = 1;
        vis[Q[i].mix] = 1;
        tot += 2;
      }
    }
    for(int i = 1;i<=n;i++)
    {
      if(vis[i]) cout<<Q[i].s;
    }
    cout<<endl;
  }
  return 0;
}
