#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<cstdlib>

int main()
{
  char s[100];
  int n;
  double a=0,b=0;
  cin>>n;
  for(int i = 1;i<=n;i++)
  {
    scanf("%s",s);
    double l,k;
    cin>>l>>k;
    a += l;
    if(k>=90) k=4.0;
        else if(k>=85) k=3.7;
        else if(k>=82) k=3.3;
        else if(k>=78) k=3.0;
        else if(k>=75) k=2.7;
        else if(k>=72) k=2.3;
        else if(k>=68) k=2.0;
        else if(k>=66) k=1.7;
        else if(k>=64) k=1.5;
        else if(k>=60) k=1.0;
        else k=0.0;
    b+=k*l;

  }

 printf("%.4lf\n",b/a);

  return 0;
}
