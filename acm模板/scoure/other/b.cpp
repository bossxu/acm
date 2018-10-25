#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define MAXN 500010
#define MAXP 500010
#define MOD 1000000007
#define SF scanf
#define PF printf
using namespace std;
bool isprime[MAXN];
int primes[MAXN],cnt;
long long fi[MAXN];
vector<pair<long long,long long> > ans[MAXP+10];
void prepare(){
    fi[1]=1;
    for(int i=2;i<=MAXN-10;i++){
        fi[i]%=MOD;
        if(isprime[i]==0){
            primes[++cnt]=i;
            fi[i]=i-1;
        }
        for(int j=1;j<=cnt&&i*primes[j]<=MAXN-10;j++){
            isprime[i*primes[j]]=1;
            if(i%primes[j]==0){
                fi[i*primes[j]]=fi[i]*primes[j];
                break;
            }
            fi[i*primes[j]]=fi[i]*fi[primes[j]];
        }
    }
    for(int i=2;i<=MAXN-10;i++)
        fi[i]=(fi[i-1]+fi[i])%MOD;
}
long long get_num(long long n){
    long long px=n%MAXP;
    for(int i=0;i<ans[px].size();i++)
        if(ans[px][i].first==n)
            return ans[px][i].second;
    return -1;
}
void push_num(long long n,long long res){
    long long px=n%MAXP;
    ans[px].push_back(make_pair(n,res));
}
long long sum(long long n){
    if(n<=MAXN-10)
        return fi[n];
    long long res=get_num(n);
    if(res>=0)
        return res;
    if(n%2==0)
        res=(((n/2)%MOD)*((n+1ll)%MOD))%MOD;
    else
        res=((n%MOD)*(((n+1ll)/2)%MOD))%MOD;
    for(long long p=2;p<=n;){
        long long len=n/(n/p)+1ll-p;
        res=(res-len*sum(n/p))%MOD;
        if(res<0)
            res+=MOD;
        p+=len;
    }
    push_num(n,res);
    return res;
}
int main(){
    prepare();
    long long n;
    /*for(int i=1;i<=10000;i++)
        if(fi[i]!=sum(i)){
            PF("Error!%d: %d %d\n",i,fi[i],sum(i));
            break;
        }*/
    SF("%lld",&n);
    PF("%lld",sum(n));
}
