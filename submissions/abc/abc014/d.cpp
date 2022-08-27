#include <bits/stdc++.h>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define FOR(i,a,b) for(int i=a; i<(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define CLR(a) memset((a), 0 ,sizeof(a))
#define PB push_back
#define MP make_pair
#define SP << " " <<
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
const long double PI  = acos(-1.0L);
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
#define chmax(a,b) a = (((a)<(b))?(b):(a))
#define chmin(a,b) a = (((a)>(b))?(b):(a))

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}


const int MAX_V=200000;
const int MAX_LOG_V=log2(MAX_V)+1;
vector<int> G[MAX_V]; // �O���t�̗��ڃ��X�g�\��
int root;             // ���m�[�h�̔ԍ�

int parent[MAX_LOG_V][MAX_V]; // �e��2^k��H���ē��B���钸�_(����ʂ�߂���ꍇ��-1�Ƃ���)
int depth[MAX_V];             // ������̐[��

void dfs(int v, int p, int d){
  parent[0][v]=p;
  depth[v]=d;
  for(int i=0; i<G[v].size(); i++){
    if(G[v][i]!=p) dfs(G[v][i],v,d+1);
  }
}

// ������
void init(int V){
  // parent[0]��depth������������
  dfs(root,-1,0);
  // parent������������
  for(int k=0; k+1<MAX_LOG_V; k++){
    for(int v=0; v<V; v++){
      if(parent[k][v]<0) parent[k+1][v]=-1;
      else parent[k+1][v]=parent[k][parent[k][v]];
    }
  }
}

// u��v��LCA�����߂�
int lca(int u, int v){
  // u��v�̐[���������ɂȂ�܂Őe��H��
  if(depth[u]>depth[v]) swap(u,v);
  for(int k=0; k<MAX_LOG_V; k++){
    if((depth[v]-depth[u])>>k&1){
      v=parent[k][v];
    }
  }
  if(u==v) return u;
  // �񕪒T����LCA�����߂�
  for(int k=MAX_LOG_V-1; k>=0; k--){
    if(parent[k][u]!=parent[k][v]){
      u=parent[k][u];
      v=parent[k][v];
    }
  }
  return parent[0][u];
}

int dist(int u, int v){
    int p = lca(u, v);
    //u-v�̋���
    return (depth[u]-depth[p])+(depth[v]-depth[p]);
}

signed main(){
	int n; cin>>n;
	rep(i,n-1){
		int x,y; cin>>x>>y; x--; y--;
		G[x].PB(y); G[y].PB(x);
	}
	root=0;
	init(n);
	int q; cin>>q;
	rep(i,q){
		int a,b; cin>>a>>b; a--; b--;
		cout<<dist(a,b)+1<<endl;
	}
	return 0;
}
