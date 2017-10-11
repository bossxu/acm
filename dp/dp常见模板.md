### 最大上升子序列
```
LIS(LDS)
template<class Cmp>  
int LIS (Cmp cmp)(nlogn)  
{  
    static int m, end[N];  
    m = 0;  
    for (int i=0;i<n;i++)  
    {  
        int pos = lower_bound(end, end+m, a[i], cmp)-end;  
        end[pos] = a[i], m += pos==m;  
    }  
    return m;  
}  
    cout << LIS(less<int>()) << endl;         //严格上升  
    cout << LIS(less_equal<int>()) << endl;   //非严格上升  
    cout << LIS(greater<int>()) << endl;      //严格下降  
    cout << LIS(greater_equal<int>()) << endl;//非严格下降  
```
### 最大公共子序列
```
留个递推公式,差不多的意思(n^2)

   dp[i][j]=dp[i-1][j-1]+1;
   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
   dp[0][0]=0;

```
