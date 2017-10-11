#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define cle(a,v) memset(a,(v),sizeof(a))
#define ll long long
const int maxn = 2e5 + 7;

struct Edge {
    int v, w, next;
} edges[maxn * 2];
int head[maxn], tot;
void addedge(int u, int v, int w) {
    edges[tot] = Edge{v, w, head[u]};
    head[u] = tot++;
}
int n, dpson[maxn], dpfa[maxn];
void dfs1(int u, int fa) {
    for (int i = head[u]; ~i; i = edges[i].next) {
        int v = edges[i].v;
        int w = edges[i].w;
        if (v != fa) {
            dfs1(v, u);
            dpson[u] += dpson[v] + w;
        }
        printf(" u==%d , dp[u] ==%d\n",u,dpson[u]);
    }
}
void dfs2(int u, int fa) {
    for (int i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].v;
        int w = edges[i].w;
        if (v == fa) continue;
        dpfa[v] = dpfa[u] + (w ? 0 : 1) + dpson[u] - dpson[v] - w;
        dfs2(v, u);
    }
}
int main() {
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
    cle(head, -1); tot = 0;
    cle(dpson, 0);
    cle(dpfa, 0);
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v, 1);
        addedge(v, u, 0);
    }
    dfs1(1, -1);
    /*
    dfs2(1, -1);
    vector<pair<int, int>> vp;
    for (int i = 1; i <= n; i++) {
        vp.push_back(make_pair(dpson[i] + dpfa[i], i));
    }
    sort(vp.begin(), vp.end());
    int t1 = vp[n - 1].first;
    int i;
    for (i = n - 2; i >= 0; i--) {
        if (vp[i].first != t1) {
            break;
        }
    }
    printf("%d\n", n - 1 - vp[n - 1].first);
    for (int j = i + 1; j < n; j++) {
        printf("%d%c", vp[j].second, j == n - 1 ? '\n' : ' ');
    }*/
    return 0;
}
