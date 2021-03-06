const int MAX = 1e6+10;
long long su[MAX],cnt;
bool isprime[MAX];
void prime()
{
    cnt=1;
    memset(isprime,0,sizeof(isprime));//初始化认为所有数都为素数
    isprime[0]=isprime[1]=1;//0和1不是素数
    for(long long i=2;i<MAX;i++)
    {
        if(!isprime[i])
            su[cnt++]=i;//保存素数i
        for(long long j=1;j<cnt&&su[j]*i<MAX;j++)
        {
            isprime[su[j]*i]=1;//筛掉小于等于i的素数和i的积构成的合数
            if (!(i%su[j]))
                break;
        }
    }
}
