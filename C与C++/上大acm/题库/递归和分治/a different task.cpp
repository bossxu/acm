#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using  namespace std;
long long ans;
long long moving(int k,int *s,int fin)
{
    if(k==0) return 0;
    if(s[k]== fin) return moving(k-1,s,fin);//�պ�ƥ��Ļ���ô����Ͳ�Ҫ��
    return moving(k-1,s,6-fin-s[k]) +(1LL<<(k-1))//��һ�����Ǽ򵥺������ĸ��Ӷ� ;
}
int main()
{
    int shu=0;
    int st[61],en[61];
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        int i;ans=0;
        for(i=1;i<=n;i++) cin>>st[i];
        for(i=1;i<=n;i++) cin>>en[i];
        int k=n;
        while(k>=1 && st[k]==en[k]) k--;
        int o=6-st[k]-en[k];
        if(k>=1)
        {
            ans=moving(k-1,st,o) + moving(k-1,en,o)+1 //�����ҵ���Ҫת�Ƶ������Ǹ�������Ҫת�Ƶ��������ǰ�ǰ �涼ת�Ƶ�һ��û���õİ�����;
        }
        printf("Case %d: %lld\n",++shu,ans);
    }
}
