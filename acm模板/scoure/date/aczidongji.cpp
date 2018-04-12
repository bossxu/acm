struct Trie
{
    int next[500010][26],fail[500010],end[500010];
    //第一个是他的边,第二个是那个失配数组,第三个是每个结点的权,字典树里面的东西
    int root,L;
    int newnode()//建新结点
    {
        for(int i = 0;i < 26;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()//初始化这颗树
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[]) //在字典树中插入单词
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
    void build()//这里就是在做那个啥失配数组
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
