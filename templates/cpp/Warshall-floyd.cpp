const int MAX_V = 200;
ll d[MAX_V][MAX_V];
int V;

void warshall_floyd(){
	rep(k,V)rep(i,V)rep(j,V) chmin(d[i][j],d[i][k]+d[k][j]);
}
