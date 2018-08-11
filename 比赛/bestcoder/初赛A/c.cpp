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
char s[10005];
struct node
{
  int l,r;
  int k;
}q[10005];
int cmp(node a,node b)
{
  if(a.k == b.k) return a.l>b.l;
  return a.k>b.k;
}
int main()
{
  int n,K;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  while (cin>>n>>K)
  {
    cin>>s;
    int len = strlen(s);
    int tot = 0;
    int l = -1;
    int k = 0;
    int pt = 0;
    int wei = 0;
    for(int i = 0;i<len;i++)
    {
      if(s[i] == '0')
      {
        if(l!=-1)
        {
          if(l == 0)
          {
            pt = k;
            l = -1;
            continue;
          }
          q[tot].l = l,q[tot].r = l + k - 1;
          q[tot++].k = k;
          l = -1;
        }
      }
      if(s[i] == '1')
      {
        if(l==-1)
        {
          l = i;k = 1;
        }
        else
        {
          k++;
        }
      }
    }
    //cout<<l<<endl;
    if(l!=-1)
    {
      q[tot].l = l,q[tot].r = l + k - 1;
      q[tot].k = k;
      //if(q[tot].l == 1) {pt = 0;}
      if(q[tot].r == n-1) {wei = k;}
      else tot++;
    }
    sort(q,q+tot,cmp);
    int ans = 0;
    if(K == 0)
    {
      if(s[0] == '1' && pt == 0) pt = wei;
      cout<<pt<<endl;
      continue;
    }
    int i;
    //cout<<pt<<" "<<wei<<endl;
    for(i = 0;i<tot;i++)
    {
      if(K<=2) break;
      int cut = 2;
      if(K>=cut)
      {
        ans += q[i].k;
        K -= cut;
      }
    }
    //cout<<"eh"<<endl;
    if(K == 1 && i<tot)
    {
      ans += max(q[i].k,wei+pt);
    }
    if(K == 2 && i<tot)
    {
      ans += max(max(q[i].k,wei)+pt,wei+q[i].k);
    }
    if(i == tot)
    {
        ans+=pt;
      if(K >= 1)
       ans+=wei;
    }
    cout<<ans<<endl;
  }
  return 0;
}
