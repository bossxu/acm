#include<stdio.h>

int count=0;//�����õ�
//row���е���˼��n:�е���˼��chess������
int Pandanger(int row, int j,int (*chess)[8])//������
{

    //�ж�һ�����Ƿ��лʺ�
    //�ж�б���Ƿ��лʺ�
    //б��ͨ�����Ϸ������·������·������Ϸ��ֽ�����

   int i,k,item=1;
   for(i=0;i<8;i++)//�ж��з���
    {
        if(*(*(chess+i)+j)!=0)
        {
           return 0;
        }
    }
    for(i=row,k=j;i>=0&&k>=0;i--,k--)//���Ϸ�
    {
        if(*(*(chess+i)+k)!=0)
        {
          return 0;
        }
    }
    for(i=row,k=j;i<8&&k<8;i++,k++)//���·�
    {
        if(*(*(chess+i)+k)!=0)
        {
          return 0;
        }
    }
    for(i=row,k=j;i>=0&&k<8;i--,k++)//���Ϸ�
    {
        if(*(*(chess+i)+k)!=0)
        {
           return 0;
        }
    }
    for(i=row,k=j;i<8&&k>=0;i++,k--)//���·�
    {
        if(*(*(chess+i)+k)!=0)
        {
            return 0;
        }
    }
    return 1;
}

void EightQueen(int row,int  n, int (*chess)[8])//�ʺ��������
{
  int i,j,chess2[8][8];
  for(i=0;i<8;i++)
  {
      for(j=0;j<8;j++)
      {
           chess2[i][j]=chess[i][j];//�����̵ĳ�ʼ��
      }
  }
  if(row==8)
  {//���������
  printf("��%d��:\n",count+1);
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                printf("%d ",*(*(chess2+i)+j));
            }
            printf("\n");
        }
        printf("\n");
        count++;
  }
  else
  {
      for(j=0;j<n;j++)//������������������һ�е�8�����
      {
          if(Pandanger(row,j,chess))//�ж�λ���Ƿ�Σ��
          {
              for(i=0;i<8;i++)
              {
                  *(*(chess2+row)+i) =0;//�еĳ�ʼ��
              }
               *(*(chess2+row)+j) =1;//ֻ����һ�еģ����������ĲŻ����һ��Ů��
               EightQueen(row +1,n,chess2);//����Ϊ�ĺ���
          }
      }
  }

}
int main()
{
    int i,j,chess[8][8];
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            chess[i][j]=0;//һ��ʼΪ�յ����̣���ʼ��
        }
    }
         EightQueen(0,8,chess);
         printf("�ܹ���%d�ֽ������",count);


    return 0;
}
