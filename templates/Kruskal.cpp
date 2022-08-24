// Kruskal
const int MAX_E = 100100;
struct edge{int u, v, cost;};

bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E; // 頂点数と辺数

struct UnionFind{
  VI par,sizes; // par[i]:iの親の番号
  UnionFind(int n) : par(n), sizes(n,1){ // 最初は全てが根であるとして初期化
    rep(i,n) par[i] = i;
  }
  int root(int x){
    if(par[x]==x) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y){
    int rx = root(x); int ry = root(y);
    if(rx==ry) return;
    if(sizes[rx]<sizes[ry]) swap(rx,ry);
    par[ry] = rx;
    sizes[rx] += sizes[ry];
  }
  bool same(int x, int y){
    return root(x)==root(y);
  }
  int size(int x){
    return sizes[root(x)];
  }
};

int kruskal(){
  sort(es,es+E,comp); // edge.costが小さい順にソートする
  UnionFind uf(V);
  int res = 0;
  rep(i,E){
    edge e = es[i];
    if(!uf.same(e.u,e.v)){
      uf.unite(e.u,e.v); res += e.cost;
    }
  }
  return res;
}
