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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
struct cmp1{
    bool operator ()(ll &a,ll &b){
        return a>b;
    }
};
int main()
{
   int n;
   while(cin>>n)
   {
     priority_queue<ll,vector<ll>,cmp1>q;
     for(int i = 1;i<=n;i++)
     {
       ll a;
       cin>>a;
       q.push(a);
     }
     ll sum = 0;
     while(q.size()>=2)
     {
       ll a,b;
       a = q.top();q.pop();
       b = q.top();q.pop();
       sum+=a+b;
       q.push(a+b);
     }
     cout<<sum<<endl;
   }
  return 0;
}
