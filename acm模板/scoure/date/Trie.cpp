//字典树的板子其实比较简单
//主要就是存一些简单的关系，而且好像可以开的挺大的，但是必须开全局才行
//不过这只是一种数据结构，他的操作还有很多其他的用处，算法也是要靠自己去实现的
//很多题型应该是对那个val进行操作
const int maxnode = 1000100,sigma_size = 26;
int trie[maxnode][sigma_size];
int val[maxnode];//这里最简单的意义在于记录那个点是否是单词结尾节点。
int sz;
inline int idx(char c) { return c-'a'; }
void init()
{
  clr(trie[0],0);
  clr(val,0);
  sz = 1;
}
void insert(char *s,int value)
{
    int u=0, n=strlen(s);
    for (int i=0; i<n; i++)
    {
        int c=idx(s[i]);
        if (trie[u][c]==0) //empty
        {
            clr(trie[sz],0);
            val[sz]=0; //not a word
            trie[u][c]=sz++;
        }
        u=trie[u][c];
    }
    val[u] = value;
}
int search(char *s)
{
    int u=0, n=strlen(s);
    for (int i=0; i<n; i++)
    {
        int c=idx(s[i]);
        if (trie[u][c]==0)
            return -1;
        u=trie[u][c];
    }
    return val[u];
}
