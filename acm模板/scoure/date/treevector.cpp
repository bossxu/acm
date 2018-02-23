//一维的
int tree[maxn];
int lowbit(int t)
{
  return t&(-t);
}
void add(int x,int y)
{
  for(int i=x;i<=n;i+=lowbit(i))
  tree[i]+=y;
}
int getsum(int x)
{
  int ans=0;
  for(int i=x;i>0;i-=lowbit(i))
    ans+=tree[i];
  return ans;
}
//二维的，自己感觉一下，需要容斥一下
int data[MAX][MAX], n;
int lowbit(int x) {
    return x&-x;
}
void Add(int x, int y, int w) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= n; j += lowbit(j)) {
            data[i][j] += w;
        }
    }
}
int Sum(int x, int y) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j -= lowbit(j)) {
            ans += data[i][j];
        }
    }
    return ans;
}
