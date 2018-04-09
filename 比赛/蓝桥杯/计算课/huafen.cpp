#include<iostream>
using namespace std;
long long a[400][400];//a[n][k]表示将数n，分成k份，每份可以是任意值
int main()
{
    long long n,k;
    cin>>n>>k;


    for (int i=1;i<=n;i++)
    {
        a[i][1]=1;//将i分成1份，只有一种分法
    }
    for (int j=1;j<=k;j++)
    {
        a[1][j]=1;//将1分成j，有一种
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=k;j++)
        {
                //当i<j时，因为此时最多分成i份，实际上相当于将i分成i份
            if(i<j)
                a[i][j]=a[i][i];
                //当i==j时，分两种情况，一种是每份分1，
                //只有一种分法，第二种至少有一份为0，此时相当于a[i][j-1]
            else if (i==j)
                a[i][j]=a[i][j-1]+1;
                //当m>n时，也分两种情况，一种是至少有一份为0，
                //相当于a[i][j-1],第二种，先将j分出来，然后将i-j再分成j份，此时相当于a[i-j][j];
            else if (i>j)
                a[i][j]=a[i-j][j]+a[i][j-1];
        }
    }
    cout<<a[n][k];
    return 0;
}
