#include <stdio.h>
#include <math.h>
int main()
{
    double x,f,s,t;
    int n;

    printf("please input x(0 to exit): ");
    scanf("%lf",&x);    // double ������ "%lf"
    while(x != 0)       ////// Ҫ��Ҫ���ѭ���������
    {
        n = 1;
        f = x;
        s = 0;
        t = f;
        while(fabs(t) >= 1e-6)     /////////////
        {
            s += f;
            n++;                    ////////////
            t = f*x*x / ((2*n-1)*(2*n-2));
            f = -t;                 /////////// ��ʵ�� t �е����
        }
        printf("%d,%f\n",n-1,s);   //////////////
        printf("please input x(0 to exit): ");
        scanf("%lf",&x);
    }
    return 0;
}
