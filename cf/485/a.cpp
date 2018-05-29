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
char s[10];
int vis[10];
char map[6][10] = {"Power","Time","Space","Soul","Reality","Mind"};
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  cin>>n;
  clr(vis,0);

  for(int i = 1;i<=n;i++)
  {
    cin>>s;
    if(s[0] == 'p') vis[1] = 1;
    if(s[0] == 'g') vis[2] = 1;
    if(s[0] == 'b') vis[3] = 1;
    if(s[0] == 'o') vis[4] = 1;
    if(s[0] == 'r') vis[5] = 1;
    if(s[0] == 'y') vis[6] = 1;
  }
  cout<<6-n<<endl;
  for(int i = 1;i<=6;i++)
  {
    if(!vis[i])
    cout<<map[i-1]<<endl;
  }
  return 0;
}
