#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int n;  
LL ji;  
const int MAXN = 1010;  
LL A[MAXN], r[MAXN];  
// 扩展 中国剩余定理 
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
    lcm = 1;  
    ji=1;
    for(int i = 1; i <= n; i++)  
    {  
        scanf("%lld", &A[i]);  
        lcm = lcm / gcd(lcm, A[i]) * A[i]; 
        ji=ji*A[i]/gcd(ji,A[i]) ;
    }  
    for(int i = 1; i <= n; i++) scanf("%lld", &r[i]);  
}  
  
LL solve()  
{  
    read_case();  
    LL a, b, c, d, x, y;  
    for(int i = 2; i <= n; i++)  
    {  
        a = A[1], b = A[i], c = r[i]-r[1];  
        ex_gcd(a, b, d, x, y);  
        if(c % d) { return -1;}  
        LL b1 = b / d;  
        x *= c / d;  
        x = (x%b1 + b1) % b1;  
        r[1] = A[1]*x + r[1];  
        A[1] = A[1]*(A[i] / d);  
    }  
    if(r[1] == 0) return lcm;  
    else return r[1];
}
  
int main()  
{  
    int T;    
    scanf("%d", &T);  
    while(T--)  
    {  
        LL m;
        cin>>m>>n;
        LL k = solve(); 
         if(m>k && k!=-1)
             printf("%d\n",1+(m-k)/ji);
         else
         printf("0\n");
    }  
   system("pause");
    return 0;  
} 