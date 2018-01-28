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
int pri[10000007],O[10000005];
bool vis[10000007];
ll pan[10000005];
int k;
void prime(int n)
{
    clr(vis,0);
    k=0;
    int m=sqrt(n+0.5);
    for(int i=2;i<=n;i++)if(!vis[i]){
        pri[k++]=i;
        for(int j=i+i;j<=n;j+=i)vis[j]=1;
    }
}
void O_la(int n)
{
    clr(O,0);
    O[1]=1;
    for(int i=2;i<=n;i++)if(!O[i]){
        for(int j=i;j<=n;j+=i){
            if(!O[j])O[j]=j;
            O[j]=O[j]/i*(i-1);
        }
    }
}

int main()
{
    int n;
        cin>>n;
        ll sum=0;           
        prime(n);
        O_la(n);
        pan[0]=0;
        for(int i=1;i<=n;i++)
        pan[i]=pan[i-1]+O[i];
        for(int i=0;i<k && pri[i]<=n;i++)
        {
            //cout<<pri[i]<<endl;
            sum+=pan[n/pri[i]]*2-1;
        }
        cout<<sum<<endl;
    return 0;
}