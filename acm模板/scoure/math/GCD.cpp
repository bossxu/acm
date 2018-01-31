//欧几里得求最大公因数
int gcd(int a,int b)
{
   return b == 0?a:gcd(n,a%b);
}
//扩展欧几里得算法
// a*x + b*y = gcd(a,b) 这个是用于 x 和 y
// 不能肯定 x，y的正负
int exgcd(int a,int b,int &x,int &y)
{
   if(b == 0)
   {
     x = 1;
     y = 0;
     return a;
   }
   int r = exgcd(b,a%b,x,y);
   int t = y;
   y = x - (a/b)*y;
   x = t;
   return r;
}
