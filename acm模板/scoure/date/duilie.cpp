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
  //map的一些常见用法
  map<int,int>q;//前面是key,后面val,这是一个映射的过程
  q.insert(make_pair(a,b)); q[a] = b,q.size()//这个是赋值的方法
  for(map<int,int>::iterator i = q.begin();i != q,end();i++) {cout<<(i->first)<<(i->second);} //这个是遍历的用法first是key,second是val
  q.count(a),q.find(a),q.clear();//这个是查key a是否出现过,前面的返回的是是否,后面的返回的是迭代器,返回的是只想那个地址的指针
  //set的用法
  set<int>q;
  q.insert(a);q.size();q.clear();
  for(set<int>::iterator j = q.begin();j!=q.end();j++) cout<<*j<<endl; //插入,遍历啥的操作
  //string一些初始化方法
  char shu[100];
  char s1[] = {"dadaa"};
  string a("sssss"),string s = "qqqq",string s1(s,3,4);//s1是s从下标3开始4个字符的拷贝
  string s2(s,2);//从s2的第二个字符开始拷贝
  string s3(shu,3);//复制字符串cs的前3个字符到s当中

}
