### 理解

> ac自动机是基于，字典树和kmp算法的一种看起来更高级的数据结构。它的主要原理感觉与kmp相似，用一个数组来记录再当前失配的情况下，他会跳转到哪个结点上。然后它用一颗树去记录那个玩意。也就是字典树。

### 能用的方面

>哪个啥，kmp算法主要是针对一个模板串，多个匹配串，ac自动机好像是针对多模匹配算法,如同给你一段字符串,问你多少个单词在这个字符串中出现过.

### 代码 <kuangbing板子>

```cpp

struct Trie
{
    int next[500010][26],fail[500010],end[500010];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 26;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now]++;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 26;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() )
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 26;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i = 0;i < len;i++)
        {
            now = next[now][buf[i]-'a'];
            int temp = now;
            while( temp != root )
            {
                res += end[temp];//其实这里的这个玩意不管怎么说应该都只是1,表示有一个单词
                end[temp] = 0;//这里的意思我感觉是在与去重
                temp = fail[temp];//向上归根
            }
        }
        return res;
    }
};
```

>>一些看法：这里的字典树它每个节点的哪个val权表示的是以这个为节点结尾的词的个数  
