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
const int MAX = 1e6+10;
long long su[MAX],cnt;
bool isprime[MAX];
void prime()
{
    cnt=1;
    memset(isprime,0,sizeof(isprime));//初始化认为所有数都为素数
    isprime[0]=isprime[1]=1;//0和1不是素数
    for(long long i=2;i<MAX;i++)
    {
        if(!isprime[i])
            su[cnt++]=i;//保存素数i
        for(long long j=1;j<cnt&&su[j]*i<MAX;j++)
        {
            isprime[su[j]*i]=1;//筛掉小于等于i的素数和i的积构成的合数
            if (!(i%su[j]))
                break;
        }
    }
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("out.txt","w",stdout);
  prime();
  cout<<cnt<<endl;
  for(int i = 1;i<cnt;i++)
  {
    cout<<su[i]<<" ";
    if(i%8 == 0) cout<<endl;
  }
  int ok;
  while(cin >> ok)
  {

  }
  return 0;
}
