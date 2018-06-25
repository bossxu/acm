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
int f[400006];
char s[400005];
void getfill(int len)
{
memset(f,0,sizeof(f)); //根据其前一个字母得到
for(int i=1;i<len;i++)
{
int j=f[i];
while(j && s[i]!=s[j])
j=f[j];
f[i+1]=(s[i]==s[j])?j+1:0;
}
}
stack<int>q;
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  while(cin>>s)
  {
    int k = strlen(s);
    getfill(k);
    q.push(k);
    while(true)
    {
      if(f[k] == 0) break;
      q.push(f[k]);
      k = f[k];
    }
    while(!q.empty())
    {

      cout<<q.top();
      if(q.size() == 1) cout<<endl;
      else cout<<" ";
      q.pop();
    }


  }
  return 0;
}
