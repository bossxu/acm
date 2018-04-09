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
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
struct node
{
  int a;
  struct node *pre;
  node(int v)
  {
    a = v;
    pre = NULL;
  }
};
class Stack
{
public:
  node *head;
  node *end;
  Stack()
  {
    head = NULL;
    end = NULL;
  }
  void init()
  {
    head = NULL;
    end = NULL;
  }
  void pop()
  {
    if(end == NULL)
    {
      printf("EMPTY\n");
    }
    else
    {
      printf("%d\n",end->a);
      end = end->pre;
      if(end == NULL)
      {
        head = NULL;
      }
    }
  }
  void push(int i)
  {
    node *p = new node(i);
    if(head == NULL)
    {
      head = p;
      end = p;
    }
    else
    {
      p->pre = end;
      end = p;
    }
  }
};
Stack s[300006];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     int n,q;
     cin>>n>>q;
     for(int i = 1;i<=n;i++)
     {
       s[i].init();
     }
     int a,b,c;
     for(int i = 1;i<=q;i++)
     {
       scanf("%d",&a);
       if(a == 1)
       {
         scanf("%d%d",&b,&c);
         s[b].push(c);
       }
       if(a == 2)
       {
         scanf("%d",&b);
         s[b].pop();
       }
       if(a == 3)
       {
         scanf("%d%d",&b,&c);
         if(s[c].head == NULL)
         {
           continue;
         }
         if(s[b].head == NULL)
         {
           s[b].head = s[c].head;
           s[b].end = s[c].end;
           s[c].init();
           continue;
         }
         s[c].head->pre = s[b].end;
         s[b].end = s[c].end;
         s[c].init();
       }
     }
   }
  return 0;
}
