//这个是单调栈,用来处理的是右边第一个比他大的
int tot  = -1;
st[++tot] = n;
for(int i = n-1;i>=1;i--)
{
  if(shu[i]>shu[st[tot]])
  {
    while(tot>=0 && shu[i]>shu[st[tot]])
    {
      tot--;
    }
    if(tot == -1)
    {
      nextmax[i] = -1;//表示它最大
    }
    else
    {
      nextmax[i] = st[tot];
    }
    st[++tot] = i;
  }
  else
  {
    nextmax[i] = st[tot];
    st[++tot] = i;
  }
}
