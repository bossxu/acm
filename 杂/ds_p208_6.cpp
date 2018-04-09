#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define mod 1e9+7
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
int pre[20];//记录他爸是谁
int height[20];//记录以他为跟节点的树的高度
int nodenum[20];//记录以他为根节点的树的节点个数
void init()
{
  for(int i = 1;i<=16;i++)
  {
    pre[i] = i;//初始化为根节点
    height[i] = 1;//为根节点的时候，高度为 1
    nodenum[i] = 1;//初始化的时候就一哥节点
  }
}
void show()
{
  for(int i = 1;i<=16;i++)
  {
    cout<<i<<"-->"<<pre[i]<<"  "; // 后面的是前面的父亲节点
    if(i%4 == 0) cout<<endl;
  }
  cout<<"---------fen------ge-------xian---------"<<endl;
}
void union_1(int i,int j)
{
   pre[j] = i;
}
void union_2(int i,int j)
{
    if(height[i]>=height[j])
    {
      pre[j] = i;
      height[i] = max(height[i],height[j]+1);//这是一个更新的过程。
    }
    else
    {
      pre[i] = j;
      height[j] = max(height[j],height[i]+1);
    }
}
void union_3(int i,int j)
{
  if(nodenum[i]>=nodenum[j])
  {
    pre[j] = i;
    nodenum[i]+=nodenum[j];//也是更新
  }
  else
  {
    pre[i] = j;
    nodenum[j]+=nodenum[i];
  }
}
void build_1()
{
  union_1(1,2),union_1(3,4),union_1(3,5),union_1(1,7),union_1(3,6),union_1(8,9),union_1(1,8),union_1(3,10),union_1(3,11),union_1(3,12),union_1(3,13);
  union_1(14,15),union_1(16,0),union_1(14,16),union_1(1,3),union_1(1,14);
}
void build_2()
{
  union_2(1,2),union_2(3,4),union_2(3,5),union_2(1,7),union_2(3,6),union_2(8,9),union_2(1,8),union_2(3,10),union_2(3,11),union_2(3,12),union_2(3,13);
  union_2(14,15),union_2(16,0),union_2(14,16),union_2(1,3),union_2(1,14);
}
void build_3()
{
  union_3(1,2),union_3(3,4),union_3(3,5),union_3(1,7),union_3(3,6),union_3(8,9),union_3(1,8),union_3(3,10),union_3(3,11),union_3(3,12),union_3(3,13);
  union_3(14,15),union_3(16,0),union_3(14,16),union_3(1,3),union_3(1,14);
}
int main()
{
  init();
  build_1();
  show();
  init();
  build_2();
  show();
  init();
  build_3();
  show();

  return 0;
}
