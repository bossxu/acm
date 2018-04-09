//欧拉函数 求的是 1 -> n-1 中与n 互质的数的个数
ll phi(ll n) //直接实现
{
  ll rea = n;
  for(int i = 2;i*i<=n;i++)
  {
    if(n%i == 0)
    {
      rea = rea - rea/i;
      while(n%i == 0) n/=i;
    }
    if(n>1)
    rea = rea - rea/n;
    return rea;
  }
}
//欧拉打表
for(int i = 1;i<=maxn;i++) phi[i] = i;
for(int i = 2;i<=maxn;i+=2) phi[i]/=2;
for(int i = 3;i<=maxn;i+=2)
{
  if(phi[i] == i)
  {
    for(j = i ;j<=maxn;j+=i)
    {
      phi[j] = phi[j]/i*(i-1);
    }
  }
}
