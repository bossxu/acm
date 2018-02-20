//1 获得当前行的数
int getnum(int x)
{
  int ret = 0;
  while(x)
  {
    x &= x-1;
    ret++;
  }
  return ret;
}
//2 看当前行左右是不是满足题设
bool check(int x)
{
  if(x & x<<1) return 0;
  return 1;
}
// 看是不是可以满足条件,和题目给的图一样,是可以放的,并且和上一个是不是会冲突
bool suit(int x,int y)
{
  if(x&y) return 0;
  return 1;
}
