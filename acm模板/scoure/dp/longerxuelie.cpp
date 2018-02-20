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
