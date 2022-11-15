vector<int> G[MAX_V]; // グラフの離接リスト表現
int root;             // 根ノードの番号

int parent[MAX_LOG_V][MAX_V]; // 親を2^k回辿って到達する頂点(根を通り過ぎる場合は-1とする)
int depth[MAX_V];             // 根からの深さ

void dfs(int v, int p, int d){
  parent[0][v]=p;
  depth[v]=d;
  for(int i=0; i<G[v].size(); i++){
    if(G[v][i]!=p) dfs(G[v][i],v,d+1);
  }
}

// 初期化
void init(int V){
  // parent[0]とdepthを初期化する
  dfs(root,-1,0);
  // parentを初期化する
  for(int k=0; k+1<MAX_LOG_V; k++){
    for(int v=0; v<V; v++){
      if(parent[k][v]<0) parent[k+1][v]=-1;
      else parent[k+1][v]=parent[k][parent[k][v]];
    }
  }
}

// uとvのLCAを求める
int lca(int u, int v){
  // uとvの深さが同じになるまで親を辿る
  if(depth[u]>depth[v]) swap(u,v);
  for(int k=0; k<MAX_LOG_V; k++){
    if((depth[v]-depth[u])>>k&1){
      v=parent[k][v];
    }
  }
  if(u==v) return u;
  // 二分探索でLCAを求める
  for(int k=MAX_LOG_V-1; k>=0; k--){
    if(parent[k][u]!=parent[k][v]){
      u=parent[k][u];
      v=parent[k][v];
    }
  }
  return parent[0][u];
}

int dist(int u, int v){
    int p=lca(u, v);
    //u-vの距離
    return (depth[u]-depth[p])+(depth[v]-depth[p]);
}
