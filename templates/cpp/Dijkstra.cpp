// Dijkstra
const int MAX_E = 100100;
const int MAX_V = 100100;
int cost[MAX_V][MAX_E]; // cost[u][v]は辺e=(u,v)のコスト(存在しないならINF)
int d[MAX_V]; // 頂点sｋらの最短距離
bool used[MAX_V]; // 既に使われたかのフラグ
int prev[MAX_V]; // 最短路の直前の頂点
int V; // 頂点数

// 始点sから各頂点への最短距離を求める
void dijkstra(int s){
  fill(d,d+V,INF); fill(used,used+V,false); fill(prev,prev+V,-1);
  d[s] = 0;
  while(true){
    int v=-1;
    // まだ使われていない頂点のうち距離が最小のものを探す
    rep(u,V) if(!used[u] && (v==-1||d[u]<d[v])) v = u;
    if(v==-1) break;
    used[v] = true;
    rep(u,V) if(d[u]>d[v]+cost[v][u]){
      d[u] = min(d[u],d[v]+cost[v][u]);
      prev[u] = v;
  }
}

// 頂点tへの最短路
VI get_path(int t){
  VI path;
  for(; t!=-1; t=prev[t]) path.push_back(t); // tがsになるまでprev[t]を辿っていく
  // このままだとt->sの順になっているので逆順にする
  reverse(path.begin(),path.end());
  return path;
}


// queueを用いた場合の実装(経路復元無し)
const int MAX_E = 100100;
const int MAX_V = 100100;
struct edge{int to, cost;};
int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s){
  // greater<PII>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<PII, vector<PII>, greater<PII> > que;
  fill(d,d+V,INF); d[s] = 0; que.push(MP(0,s));
  while(!que.empty()){
    PII p = que.top(); que.pop();
    int v = p.second;
    if(d[v]<p.first) continue;
    rep(i,G[v].size()){
      edge e = G[v][i];
      if(d[e.to]>d[v]+e.cost){
        d[e.to] = d[v]+e.cost;
        que.push(PII(d[e.to], e.to));
      }
    }
  }
}
