//头文件
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<map>
struct cmp1{
    bool operator ()(int &a,int &b){
        return a>b;//最小值优先
    }
};
int main()
{
  //优先队列
  priority_queue<int,vector<int>,cmp1>que1;
  que1.push(i);que1.top();que1.pop();que1.empty();que1.clear();//进，顶，出，空, 删，
  //排序
  sort(shu,shu+n,cmp);//范围，排序方式
  //容器
  vector<int>q2;vector<int> q2_1{1,2,3,4};
  q2.push_back(i);q2.top();q2.pop();q2.empty();q2.clear();q2.size();
  //string一些初始化方法
  char shu[100];
  char s1[] = {"dadaa"};
  string a("sssss"),string s = "qqqq",string s1(s,3,4);//s1是s从下标3开始4个字符的拷贝
  string s2(s,2);//从s2的第二个字符开始拷贝
  string s3(shu,3);//复制字符串cs的前3个字符到s当中

}
