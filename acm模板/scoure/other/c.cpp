#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#define SF scanf
#define PF printf
#define MAXN 5000010
#define MAXP 2181271
using namespace std;
bool isprime[MAXN],found;
int primes[MAXN],cnt,mu[MAXN];
map<long long,int> ans;
/*vector<pair<long long,long long> >ans[MAXP+10];
long long get_num(long long x){
    found=1;
    long long px=x%MAXP;
    for(int i=0;i<ans[px].size();i++)
        if(ans[px][i].first==x)
            return ans[px][i].second;
    found=0;
    return 0;
}
void push_num(long long x,long long val){
    long long px=x%MAXP;
    ans[px].push_back(make_pair(x,val));
}*/
void prepare(){
    mu[1]=1;
    for(int i=2;i<=MAXN-10;i++){
        if(isprime[i]==0){
            mu[i]=-1;
            primes[++cnt]=i;
        }
        for(int j=1;j<=cnt&&primes[j]*i<=MAXN-10;j++){
            isprime[i*primes[j]]=1;
            if(i%primes[j]==0){
                mu[i*primes[j]]=0;
                break;
            }
            mu[i*primes[j]]=-mu[i];
        }
    }
    for(int i=1;i<=MAXN-10;i++)
        mu[i]=mu[i-1]+mu[i];
}
long long l,r;
long long sum(long long n){
    if(n<=MAXN-10)
        return mu[n];
    if(ans.count(n)!=0)
        return ans[n];
    /*long long res=get_num(n);
    if(found==1)
        return res;*/
    long long res=1ll;
    for(long long q=2;q<=n;){
        long long len=n/(n/q)+1ll-q;
        res-=sum(n/q)*len;
        q+=len;
    }
    ans[n]=res;
    //push_num(n,res);
    return res;
}
int main(){
    prepare();
    SF("%lld%lld",&l,&r);
    PF("%lld",sum(r)-sum(l-1));
}
