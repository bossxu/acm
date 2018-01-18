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
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int n;ll m;
struct node
{
	ll num;
	ll time;
	int index;
	friend bool operator<(node a,node b)
	{
		if(a.num == b.num)
		{
			return a.time>b.time;
		}
		return 	a.num > b.num;
	}
}shu[200005];
bool cmp(node a,node b)
{
  return a.time < b.time;
}
int main()
{

  while(cin>>n>>m)
  {
	priority_queue<node>q;
    for(int i = 1;i<=n;i++)
    {
		cin>>shu[i].num>>shu[i].time;
		shu[i].index = i;
    }
    sort(shu+1,shu+n+1,cmp);
	int num = 0,sum = 0;
	for(int i = 1;i<=n;i++)
	{
		if(sum+shu[i].time <= m && shu[i].num>=num+1 && (q.empty()||q.top().num>=num+1))
		{
			q.push(shu[i]);
			num++;
			sum+=shu[i].time;
		}
		else
		{
			if(sum+shu[i].time>m)
			{
				break;
			}
			else
			{
				if(sum+shu[i].time-q.top().time <=m && q.top().num < shu[i].num)
				{
					sum += shu[i].time - q.top().time;
					q.pop();
					q.push(shu[i]);
				}
			}
		}
	}
	ll z = m - sum;
	stack<int> st;
	int o = num;
	for(int i = 1;i<=n;i++)
	{
	   if(z >= shu[i].time && shu[i].num < q.top().num)
	   {
		   num++;
		   if(num>q.top().num)
			   {
           num--;
           break;
         }
		   st.push(shu[i].index);
		   z -= shu[i].time;
	   }
       if(z<shu[i].time)
	   {
		   break;
	   }
	}
	cout<<o<<endl;
	cout<<num<<endl;
	while(!q.empty())
	{
		cout<<q.top().index<<" ";
		q.pop();
	}
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;


  }

  return 0;
}
