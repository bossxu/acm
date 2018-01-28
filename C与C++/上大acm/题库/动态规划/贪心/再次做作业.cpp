#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxnum 1010

using namespace std;

int use[maxnum];

typedef struct node
{
    int deadline;
    int score;
}ss;

int cmp(ss a , ss b)
{
    if(a.score != b.score)
        return a.score > b.score;
    else
        return a.deadline < b.deadline;
}

int main()
{
    int n;
    scanf("%d",&n);

    while (n--)
    {
        int t;
        ss a[maxnum];
        scanf("%d",&t);

        for (int i = 0 ; i < t ;i++)
            scanf("%d",&a[i].deadline);

        for (int i = 0 ; i < t; i++)
            scanf("%d",&a[i].score);

        sort (a,a+t,cmp);
        int sum = 0 , j;
        memset(use,0,sizeof(use));

        for (int i = 0 ; i < t ;i++)
        {
           for (j = a[i].deadline ; j > 0 ;j--)
           {
               if(!use[j])
                {
                    use[j] = 1;
                    break;
                }
           }

           if(j == 0)
            sum += a[i].score;
        }
        printf("%d\n",sum);
    }
    return 0;
}
