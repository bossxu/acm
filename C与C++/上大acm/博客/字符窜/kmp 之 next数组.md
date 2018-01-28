# kmp之next数

## next 数组的作用是很强的，但是我只能说，理解它的作用，并不能说完全掌握，我先在想通过两道题，来找点那种next 数组，如果只通过他，我能干些什么。
###  一开始，我对kmp算法的理解，很浅，认为只是用来解决字符串的匹配问题，然后，做了几道入门题，发现题目的出发点主要还是在于对next数组的利用，当然我的水平很低，只做了几道简单的题。
### 题目的目的都是在让你利用next数组进行一些操作。

### next数组，又叫失配函数，目的在于匹配的时候，减少算法复杂度，然后我们就要理解为什么要从那个失配的地方开始，因为，前面地方的都能与之前匹配，所以才这样做，讲的好听点就是周期性（这玩意说不清楚，我也只是相当于写日记一样，记录点每天学到的，你们想要搞懂还是去看大佬到博客）

### 关键就转换成如何去利用他的周期性。看题，找感觉。

For each prefix of a given string S with N characters (each character has an ASCII code between 97 and
126, inclusive), we want to know whether the prefix is a periodic string. That is, for each i (2 ≤ i ≤ N)
we want to know the largest K > 1 (if there is one) such that the prefix of S with length i can be
written as AK, that is A concatenated K times, for some string A. Of course, we also want to know
the period K.
## Input
The input file consists of several test cases. Each test case consists of two lines. The first one contains
N (2 ≤ N ≤ 1000000) the size of the string S. The second line contains the string S. The input file
ends with a line, having the number zero on it.
## Output
For each test case, output ‘Test case #’ and the consecutive test case number on a single line; then, for
each prefix with length i that has a period K > 1, output the prefix size i and the period K separated
by a single space; the prefix sizes must be in increasing order. Print a blank line after each test case.
## Sample Input
3
aaa
12
aabaabaabaab
0
## Sample Output
Test case #1
2 2
3 3
Test case #2
2 2
6 2
9 3
12 4

这道题就是一道很基础的字符串的周期问题，因为我对这个的理解不深，我就记录下我是怎么想的。
1.我先用模版把样例的next数组输出，先看下最智障的做法，我找规律，看下有没有什么好找的。然后还真找到几个。
12
aabaabaabaab
Test case #1
ji[1]==0
ji[2]==1
ji[3]==0
ji[4]==1
ji[5]==2
ji[6]==3
ji[7]==4
ji[8]==5
ji[9]==6
ji[10]==7
ji[11]==8
ji[12]==9
2 2  == 2/(2-1)
6 2  == 6/(6-3)
9 3  == 9/(9-6)
12 4 == 12/(12-9)
虽然很智障，但却是很有效。不是吗；当然做题可以这么做，反思后时自然不能这么做。
2：就拿上面的举例子，我用s[]数组来记录字符串。对于s[2],就是b来说，我就要b看前面有几个轮回，而且是b前面，所以只有aa;我们看起来很简单，就周期是a，两个周期；然后嘛，我们看下怎么搞。我们现在知道2的前缀是1；代表他直接指向的是上一个，中间就差一个，所以我们这时候要有个感觉，它的周期长度是1；而且如果想要刚好还处在周期的末尾，才能说的上对得上题目，对吧。所以也就解释了 前面的算式。
贴个代码，顺便记录下next数组怎么做的。

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
#include<map>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define mod 1e9+7
const int maxn = 1e6+5;
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
char a[maxn];
int ji[maxn];

int main()
{
  int n, co = 0;
  while(scanf("%d",&n)==1 && n)
  {
    scanf("%s",a);
    ji[0]=0,ji[1]=0;
    for(int i=1;i<n;i++)
    {
        int j=ji[i];
        while(j && a[i]!=a[j]) j=ji[j];
        ji[i+1]=(a[i]==a[j] ? j+1:0) ; 
    }
    printf("Test case #%d\n",++co);
   /* for(int i=1;i<=n;i++)//这是我dibug的方法，牛逼吧
    {
        printf("ji[%d]==%d \n",i,ji[i]);
    }*/
    for( int i=2;i<=n;i++)
    {
        if(ji[i]>0 && i%(i-ji[i])==0) printf("%d %d\n",i,i/(i-ji[i]));
    }
    putchar('\n');
  }    
    return 0; 
}
```
日记日记，如果写的不好，坑定是写的不好啦，凑合凑合看吧

--langman