int color[N], graph[N][N];

//0为白色，1为黑色
bool bfs(int s, int n) {
    queue<int> q;
    q.push(s);
    color[s] = 1;
    while(!q.empty()) {
        int from = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) {
            if(graph[from][i] && color[i] == -1) {
                q.push(i);
                color[i] = !color[from];//染成不同的颜色
            }
            if(graph[from][i] && color[from] == color[i])//颜色有相同，则不是二分图
                return false;
        }
    }
    return true;
}  
