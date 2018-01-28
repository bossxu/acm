#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int n;  
int times;  
  
const int MAXN = 1010;  
LL A[MAXN], r[MAXN];  
  
LL lcm;  
  
LL gcd(LL a, LL b)  
{  
    return b == 0? a : gcd(b, a%b);  
}  
  
void ex_gcd(LL a, LL b, LL &d, LL &x, LL &y)  
{  
    if(!b) { d = a; x = 1; y = 0;}  
    else { ex_gcd(b, a%b, d, y, x); y -= x*(a/b);}  
}  
  
void read_case()  
{  
    scanf("%d", &n);  
    lcm = 1;  
    for(int i = 1; i <= n; i++)  
    {  
        scanf("%lld", &A[i]);  
        lcm = lcm / gcd(lcm, A[i]) * A[i];  
    }  
    for(int i = 1; i <= n; i++) scanf("%lld", &r[i]);  
}  
  
void solve()  
{  
    read_case();  
    printf("Case %d: ", ++times);  
    LL a, b, c, d, x, y;  
    for(int i = 2; i <= n; i++)  
    {  
        a = A[1], b = A[i], c = r[i]-r[1];  
        ex_gcd(a, b, d, x, y);  
        if(c % d) { printf("-1\n"); return ;}  
        LL b1 = b / d;  
        x *= c / d;  
        x = (x%b1 + b1) % b1;  
        r[1] = A[1]*x + r[1];  
        A[1] = A[1]*(A[i] / d);  
    }  
    if(r[1] == 0) printf("%lld\n", lcm);  
    else printf("%lld\n", r[1]);  
}  
  
int main()  
{  
    int T;  
    times = 0;  
    scanf("%d", &T);  
    while(T--)  
    {  
        solve();  
    }  
    system("pause");
    return 0;  
} 