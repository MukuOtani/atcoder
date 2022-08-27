#include<bits/stdc++.h>
using namespace std;
int n, e, i, j;
vector<vector<pair<int, int> > > g;
vector<int> color;
bool v[111001];
void col(int n) {
   queue<int> q;
   int c = 0;
   set<int> vertex_colored;
   if(v[n])
      return;
      v[n] = 1;
   for(i = 0;i<g[n].size();i++) {
      if(color[g[n][i].second]!=-1) {
         vertex_colored.insert(color[g[n][i].second]);
      }
   }
   for(i = 0;i<g[n].size();i++) {
      if(!v[g[n][i].first]) {
         q.push(g[n][i].first);
      }
      if(color[g[n][i].second]==-1) {
         while(vertex_colored.find(c)!=vertex_colored.end())
            c++;
            color[g[n][i].second] = c;
            vertex_colored.insert(c);
            c++;
      }
   }
   while(!q.empty()) {
      int temp = q.front();
      q.pop();
      col(temp);
   }
   return;
}
int main() {
   int u,w;
   set<int> empty;
   // cout<<"Enter number of vertices and edges respectively:";
   // cin>>n>>e;
   // cout<<"\n";
	 cin>>n; e=n-1;
   g.resize(n); //number of vertices
   color.resize(e,-1); //number of edges
   memset(v,0,sizeof(v));
   for(i = 0;i<e;i++) {
      // cout<<"\nEnter edge vertices of edge "<<i+1<<" :"<<"\n";
      cin>>u>>w;
      u--; w--;
      g[u].push_back(make_pair(w,i));
      g[w].push_back(make_pair(u,i));
   }
   col(0);
	 int ans = 0;
	 for(i = 0;i<e;i++) {
		 ans = max(ans,color[i]+1);
	 }
	 cout << ans << endl;
   for(i = 0;i<e;i++) {
      // cout<<"Edge "<<i+1<<" is coloured with colour "<<color[i]+1
      // << "\n";
			cout << color[i]+1 << endl;
   }
}
