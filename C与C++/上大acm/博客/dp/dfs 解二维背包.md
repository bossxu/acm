## dfs解二维背包
>当背包空间过大而且物品比较少的时候可以用
[hdu 3448](https://vjudge.net/problem/HDU-3448)

#### 讲道理这玩意别人怎么想到的，可怕，真的可怕
***
### 看题吧
0/1 bag problem should sound familiar to everybody. Every earth man knows it well. Here is a mutant: given the capacity of a bag, that is to say, the number of goods the bag can carry (has nothing to do with the volume of the goods), and the weight it can carry. Given the weight of all goods, write a program that can output, under the limit in the above statements, the highest weight. 
>Input
Input will consist of multiple test cases The first line will contain two integers n (n<=40) and m, indicating the number of goods and the weight it can carry. Then follows a number k, indicating the number of goods, k <=40. Then k line follows, indicating the weight of each goods The parameters that haven’t been mentioned specifically fall into the range of 1 to 1000000000. 
>Output
For each test case, you should output a single number indicating the highest weight that can be put in the bag. 
>Sample Input
5 100
8
8 64 17 23 91 32 17 12
5 10
3
99 99 99
>Sample Output
99
0
***
相当于说，你这个背包有容量，然后又告诉你买的东西数量有限制，问你能买的最大的重量是多少。
```cpp
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
const double eps = 1e-6;
// 知识点分解：dfs 解二维背包
int a[45];
int n,m,ans;
int k;
void dfs(int t,int i, int x)
{
    ans=max(ans,x);
   if(i>k) return ;
   if(t+1<=n && x+a[i]<=m)
   {
       dfs(t+1,i+1,x+a[i]);
   }
   dfs(t,i+1,x);
}
bool cmp(int a, int b) {return a>b;}
int main()
{
    while(cin>>n>>m)
    {
        cin>>k;
        int sum=0;
        for(int i=1;i<=k;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+k+1,cmp);
        for(int i=1;i<=n;i++)
       {
          sum+=a[i];
       }
       if(sum<=m)
        {
            cout<<sum<<endl;
            continue;
        }
        ans = 0;
        dfs(0,1,0);
        cout<<ans<<endl;
    }
    return 0;
}

```
真的想不到，这个点。