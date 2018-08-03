const int mod = (479<<21)+1;
const double eps = 1e-6;
#define ll long long 
//ntt 快速数论变换，相对于fft，它的一个优点在于可以处理模的情况，对于fft
//来说，更多的是在于精度不大的时候，因为他是把问题转换成了用原根而不是单位负根去处理问题
//所以我们首先需要对模数找到原根，他这里操作的长度也是2^n次方的数 这里的原根也是会变化的
//这里的模数必须是梅森素数
//这里是一个板子处理两数相乘；
const int g = 3;
const int maxn = 1<<18;
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = res*a%mod;
    a = a*a%mod;
    b>>=1;
  }
  return res;
}
int rev(int x,int r)
{
  int ans = 0;
  for(int i = 0;i<r;i++)
  {
    if(x&(1<<i))
    {
      ans += 1<<(r-i-1);
    }
  }
  return ans;
}
void NTT(int n,ll A[],int on)
{
  int r = 0;
  for(;;r++)
  {
    if((1<<r) == n) break;
  }
  for(int i = 0 ;i<n;i++)
  {
    int tmp = rev(i,r);
    if(i<tmp)
      swap(A[i],A[tmp]);
  }
  for(int s = 1;s<=r;s++)
  {
    int m = 1<<s;
    ll wn = quick(g,(mod-1)/m);
    for(int k = 0;k<n;k+=m)
    {
      ll w = 1;
      for(int j = 0;j<m/2;j++)
      {
        ll t,u;
        t = w*(A[k+j+m/2]%mod)%mod;
        u = A[k+j]%mod;
        A[k+j] = (u+t)%mod;
        A[k+j+m/2] = ((u-t)%mod+mod)%mod;
        w = w*wn%mod;
      }
    }
  }
  if(on == -1)
  {
    for(int i = 1;i<n/2;i++)
    {
      swap(A[i],A[n-i]);
    }
    ll inv = quick(n,mod-2);
    for(int i = 0;i<n;i++)
    {
      A[i] = (A[i]%mod)*inv%mod;
    }
  }

}
ll A[maxn],B[maxn];
ll ans[maxn];
int main()
{
  string s1,s2;
  while(cin>>s1>>s2)
  {
    int n = s1.size();
    int m = s2.size();
    clr(A,0),clr(B,0);
    int len = 1;
    while(len<max(n,m)) len<<=1; // 理论长度
    for(int i = n-1;i>=0;i--)    //预处理出来
    {
      A[i] = s1[n-i-1]-'0';
    }
    for(int i = m-1;i>=0;i--)
    {
      B[i] = s2[m-i-1]-'0';
    }
    //处理的关键
    NTT(len*2,A,1);
    NTT(len*2,B,1);
    for(int i = 0;i<2*len;i++)
      A[i] = A[i]*B[i]%mod;
    NTT(len*2,A,-1);
    clr(ans,0);
    for(int i = 0;i<2*len;i++)
    {
      ans[i] += A[i];
      if(ans[i]>=10)
      {
        ans[i+1] += ans[i]/10;
        ans[i]%=10;
      }
    }
    int e = 0;
    for(int i = 2*len-1;i>=0;i--)
    {
      if(ans[i])
      {
        e = i;
        break;
      }
    }
    for(int i = e;i>=0;i--)
    {
      cout<<ans[i];
    }
    cout<<endl;
  }
  return 0;
}
