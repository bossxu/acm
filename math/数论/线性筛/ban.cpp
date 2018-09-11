#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
<<<<<<< HEAD
=======
=======

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
<<<<<<< HEAD
const int N=1e4+5;
=======
>>>>>>> 34ebe2c4834c6ac7a1885daef961968cf543c62c
>>>>>>> 4b41dfce3a190734861af3d94734560667d2d877
const int N=1e5+5;
>>>>>>> 7dd9a871e17629e33350dc29ea4de5dc587b2199
bool mark[N];
int prim[N];
int cnt;
void initial()
{
    cnt=0;
    for (int i=2 ; i<N ; ++i)
    {
        if (!mark[i])
            prim[cnt++]=i;
        for (int j=0 ; j<cnt && i*prim[j]<N ; ++j)
        {
            mark[i*prim[j]]=1;
            if (!(i%prim[j]))
                break;
        }
    }
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  initial();
  int tot = 1;
  cout<<cnt<<endl;
  while(cin>>n)
  {
    cout<<prim[n]<<" ";
  }
  return 0;
}
