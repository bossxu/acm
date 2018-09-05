// 线性基 ，具体多少东西就不细写了
// 可以理解为用一些向量通过加减乘除来表示其他所有的点。
struct Linear_Basis
{
    LL b[63],nb[63],tot;

    void init()
    {
        tot=0;
        memset(b,0,sizeof(b));
        memset(nb,0,sizeof(nb));
    }
    bool ins(LL x)
    {
        for(int i=62;i>=0;i--)
            if (x&(1LL<<i))
            {
                if (!b[i]) {b[i]=x;break;}
                x^=b[i];
            }
        return x>0;
    }
    LL Max(LL x)
    {
        LL res=x;
        for(int i=62;i>=0;i--)
            res=max(res,res^b[i]);
        return res;
    }
    LL Min(LL x)
    {
        LL res=x;
        for(int i=0;i<=62;i++)
            if (b[i]) res^=b[i];
        return res;
    }
    void rebuild()
    {
        for(int i=62;i>=0;i--)
            for(int j=i-1;j>=0;j--)
                if (b[i]&(1LL<<j)) b[i]^=b[j];
        for(int i=0;i<=62;i++)
            if (b[i]) nb[tot++]=b[i];
    }
    LL Kth_Max(LL k)
    {
        LL res=0;
        for(int i=62;i>=0;i--)
            if (k&(1LL<<i)) res^=nb[i];
        return res;
    }

} LB;
