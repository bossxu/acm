#include<algorithm>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define PII pair<int,int>
#define MP(X,Y) make_pair(X,Y)
#define X first
#define Y second

int G[105][105];
int vis[105][105];
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };//方向问题
int n, m;

bool in(int x, int y)//目的是看是否能再走下去
{
	if (x < 0 || x >= m || y < 0 || y >= n)return 0;
	return 1;
}

/*int dfs(int x, int y)//查找的代码 目的在与记录步数    深度搜索
{
	if (!in(x, y) || vis[x][y] == 1 || G[x][y] == 1)return 0;//能不能走
	if (x == m - 1 && y == n - 1)return 1; //找到了额，返回
	vis[x][y] = 1;
	int ans = 0;
	for (int i = 0; i < 4; ++i) {//迭代查找
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		ans += dfs(tx, ty);
	}
	return ans;
}*/

bool bfs()//这是能不俄能走的问题    广度搜索
{
	queue< pair<int, int> > q;//数据结构中的   栈的问题
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		PII S = q.front();
		q.pop();}
		int x = S.X, y = S.Y; //上面#define
		if (x == m - 1 && y == n - 1)return true;
		for (int i = 0; i < 4; ++i) {
			int tx = x + dir[i][0];
			int ty = y + dir[i][1];
			if (in(tx, ty) && G[tx][ty] == 0 && vis[tx][ty] == 0) {
				vis[tx][ty] = 1;
				q.push(make_pair(tx, ty));
			}
		}
	}
	return false;
}

int main()
{
	while (cin >> n >> m) {
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j)
				scanf("%d", &G[i][j]);
		}
		//cout<<((dfs(0,0) > 0)? "Y":"N")<<endl;
		cout << (bfs() ? "Y" : "N") << endl;
	}
	return 0;
}
