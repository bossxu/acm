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
    int t,n;
    int a[50];
    cin>>t;
    while(t--)
    {
        cin>>n;
        int s=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            s^=a[i];
        }
        if(s!=0)
        cout<<"John"<<endl;
        else
        cout<<"Brother"<<endl;
    }
    return 0;
}