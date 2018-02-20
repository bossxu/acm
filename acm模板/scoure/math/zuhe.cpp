LL C[1005][1005];
void init()
{
    C[0][0] = 1;
    C[1][0] = C[1][1] = 1;
    for(int i = 2; i <= 1000; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
}
