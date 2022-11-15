// Bellman-Ford
const int MAX_E = 100100;
const int MAX_V = 100100;
struct edge{int from, to, cost;};
edge es[MAX_E]; //辺
int d[MAX_V]; //最短距離
int V, E;

// s番目の頂点から各頂点への最短距離を求める
void shortest_path(int s){
  rep(i,V) d[i]=INF;
  d[s] = 0;
  while(true){
    bool update = false;
    rep(i,E){
      edge e = es[i];
      if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost){
        d[e.to] = d[e.from]+e.cost;
        update = true;
      }
    }
    if(!update) break;
  }
}

// trueなら負の閉路が存在する
bool find_negative_loop(){
  memset(d,0,sizeof(d));
  rep(i,V) rep(j,E){
    edge e = es[j];
    if(d[e.to]>d[e.from]+e.cost){
      d[e.to]>d[e.from]+e.cost
      // n回目にも更新があるなら負の閉路が存在する
      if(i==V-1) return true;
    }
  }
  return false;
}
