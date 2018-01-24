 int par[maxn];
 int rank[maxn];

 void init()
 {
   for(int i = 1;i<=n;i++)
   {
     par[i] = i;
     rank[i] = 0;
   }
 }

 int find(int x)
 {
   return x==par[x]?x:find(par[x]);
 }
