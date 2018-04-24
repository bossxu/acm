//快速判素数的一个随机算法。他能处理很大的数字用那个飞马小定理
//其中要注意的点就是 一个别抱longlong 的精度，还有就是乘法也需要经行处理不过都是板子
//第三点就是经量预处理，还有这个算法是随机的所以还是有可能不行的。
const int MAXN = 65;
ll x[MAXN];//这我也不晓得用来干啥的
int flag = 0;
ll multi(ll a, ll b, ll p) {
    ll ans = 0;
    while(b) {
        if(b&1LL) ans = (ans+a)%p;
        a = (a+a)%p;
        b >>= 1;
    }
    return ans;
}
ll qpow(ll a, ll b, ll p) {
    ll ans = 1;
    while(b) {
        if(b&1LL) ans = multi(ans, a, p);
        a = multi(a, a, p);
        b >>= 1;
    }
    return ans;
}
bool Miller_Rabin(ll n) {
    if(n == 2) return true;
    int s = 5, i, t = 0; //s是随机函数
    ll u = n-1;
    while(!(u & 1)) {
        t++;
        u >>= 1;
    }
    while(s--) {
        ll a = rand()%(n-2)+2;
        x[0] = qpow(a, u, n);
        for(i = 1; i <= t; i++) {
            x[i] = multi(x[i-1], x[i-1], n);
            if(x[i] == 1 && x[i-1] != 1 && x[i-1] != n-1) return false;
        }
        if(x[t] != 1) return false;
    }
    return true;
}
