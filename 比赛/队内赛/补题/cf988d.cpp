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
set<ll>q;
//这题一看上去也是很难,但是事实上很简单的.
//就是你要去找一些规律出来.
//还有多学着用stl
void slove()
{
  for(set<ll>::iterator i = q.begin();i != q.end();i++)
  {
    for(int j = 0;j<34;j++)
    {
      ll st = *i+(1<<j);
      if(q.count(st) && q.count(st+(1<<j)))
      {
        cout<<3<<endl;
        cout<< *i <<" "<<st<<" "<<(st+(1<<j))<<endl;
        return;
      }
    }
  }
  for(set<ll>::iterator i = q.begin();i != q.end();i++)
  {
    for(int j = 0;j<34;j++)
    {
      ll st = *i+(1<<j);
      if(q.count(st))
      {
        cout<<2<<endl;
        cout<< *i <<" "<<st<<endl;
        return;
      }
    }
  }
  for(set<ll>::iterator i = q.begin();i != q.end();i++)
  {
        cout<<1<<endl;
        cout<< *i <<endl;
        return;

  }
}
int main()
{

  std::ios::sync_with_stdio(false);
   int n;
   while(cin>>n)
   {
     ll op;
     for(int i = 1;i<=n;i++)
     {
       cin>>op;
       q.insert(op);
     }

     slove();
   }

  return 0;
}
