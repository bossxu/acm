#include<bits/stdc++11>
using namespace std;
//版子
struct complex
{
    double r,i;
    complex(double _r = 0.0,double _i = 0.0)
    {
        r = _r; i = _i;
    }
    complex operator +(const complex &b)
    {
        return complex(r+b.r,i+b.i);
    }
    complex operator -(const complex &b)
    {
        return complex(r-b.r,i-b.i);
    }
    complex operator *(const complex &b)
    {
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
const int MAXN = 200010;
complex x1[MAXN],x2[MAXN];//这一个是第一个多项式的系数，第二个是第二个多项式的系数
char str1[MAXN/2],str2[MAXN/2];//这是未处理的输入字符
int sum[MAXN];//这是答案所放的位置
/*
 * 进行FFT和IFFT前的反转变换。
 * 位置i和 （i二进制反转后位置）互换
 * len必须去2的幂
 */
void change(complex y[],int len)
{
    int i,j,k;
    for(i = 1, j = len/2;i < len-1; i++)
    {
        if(i < j)swap(y[i],y[j]);
        //交换互为小标反转的元素，i<j保证交换一次
        //i做正常的+1，j左反转类型的+1,始终保持i和j是反转的
        k = len/2;
        while( j >= k)
        {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}
/*
 * 做FFT
 * len必须为2^k形式，
 * on==1时是DFT，on==-1时是IDFT
 */
void fft(complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2; h <= len; h <<= 1)
    {
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j+=h)
        {
            complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                complex u = y[k];
                complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}
void ans()
{
	//step 1
	int len = 1;
	int len1 = strlen(str1),len2 = strlen(str2);
	while(len<2*len1 || len<2*len2)	len<<=1;//第一步确定len相当于在确定那个最高能达到什么程度。
	//step 2
  for(int i = 0;i<len1;i++)	//第二膊就是把系数表示用点来表示，挺复杂的，首先就是前补0，变成len位的数，然后反向放入那个存储的数组中
   x1[i] = complex(str1[len1-1-i]-'0',0);
 for(int i = len1;i<len;i++)
   x1[i] = complex(0,0);
 for(int i = 0;i<len2;i++)
   x2[i] = complex(str2[len2-1-i]-'0',0);
 for(int i = len2;i<len;i++)
   x2[i] = complex(0,0);
	//step 3
	fft(x1,len,1);fft(x2,len,1);//第三步反正就是这意思，我也不懂这个是啥原理
	for(int i = 0;i<len;i++)
	{
		x1[i] = x1[i]*x2[i];
	}
	fft(x1,len,-1);
	for(int i = 0;i<len;i++)
	{
		sum[i] = (int)(x1[i].r+0.5);
	}
	//step 4
	//这就是自己加工了，这里面存的是答案，不过这也是倒着存的，注意去前导0，因为这里len是在最坏情况下的一个解决方案，有可能达不到。


}
