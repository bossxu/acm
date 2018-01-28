#include<stdio.h>
int main()
{
    int i,item;
    float fen;
    item=1;fen=1;
    for(i=1;item<=1000000;i++)
    {
        item=item*i;
        fen=fen+1.0/item;

    }
    printf("%f",fen);
    return 0;
}
