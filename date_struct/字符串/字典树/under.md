### 字典树

>以字母为边,结点存的是那些需要存的信息,用标记去申明这个是什么东西.然后用一个数组去存关系.trie[i][j] 表示的就是编号为i的那个结点的第j个孩子是什么.一般来说,其实我们的j是那个字母集相对于首字母的偏移量.

#### 主要的一些操作
* 创建

```cpp
struct trie
{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;
    trie() { sz=1; memset(ch[0],0,sizeof(ch[0])); }
    inline int idx(char c) { return c-'a'; }
}
```
* 插入

```cpp
void insert(char *s, int vv)
{
        int u=0, n=strlen(s);
        for (int i=0; i<n; i++)
        {
            int c=idx(s[i]);
            if (ch[u][c]==0) //empty
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0; //not a word
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=vv;
}
```
* 寻找

```cpp
bool search(char *s, int vv)
    {
        int u=0, n=strlen(s);
        for (int i=0; i<n; i++)
        {
            int c=idx(s[i]);
            if (ch[u][c]==0)
                return false;
            u=ch[u][c];
        }
        if (val[u]==0) return false; 
        return true;
    }
```

#### 个人的一些想法
像这个数据结构,一般来说,比较难的题都会在我们构建的这颗树上做文章.像很多的异或运算都在那个里面.
