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
const double eps = 1e-6;
// 知识点分解：
int main()
{
    ll n;
    ll a[15]={1,4,27,256,3125,46656,823543,16777216,387420489,10000000000,
    285311670611,8916100448256,302875106592253,11112006825558016,437893890380859375};
    while(cin>>n)
    {
        int i=0;
        for( i=0;i<15;i++)
        {
            if(a[i]>n)
            break;
        }
       cout<<i<<endl;
    }
    return 0;
}