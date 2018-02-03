//欧拉函数 求的是 1 -> n-1 中与n 互质的数的个数
ll phi(ll n) //直接实现
{
  ll rea = n;
  for(int i = 2;i*i<=n;i++)
  {
    if(n%i == 0)
    {
      rea = rea - rea/i;
      do n/=i;
      while(n%i == 0);
    }
    if(n>1)
    rea = rea - rea/n;
    return rea;
  }
}
//素数表
bool check[50000];
int p[20000];
void prim()//线性筛素数
{
  clr(check,0);


}
