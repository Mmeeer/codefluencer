#include<queue>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
// ene huu code ni 4n jiliin umnu buyu hereglegchiin function uusgelgui bodson bolhoor oiloghod arai hyalbar baih
// harj baigaachlan vectoriin dotor pair gdg ugugdliin turul baigaa. pair ni 2 hos utga hadgalah chadvartai first, second gsn nereer duudaj boldog huvisagch yum
// https://www.hackerrank.com/challenges/dijkstrashortreach/problem


int main(){
	int t, V, E, S, path[3001], i, v, u, m, size, tmp;
	bool vis[3001];
	vector<pair<int, int> > adj[3001];
	priority_queue<pair<int, int> > q;
	cin >> t;
	while(t--){
		cin >> V >> E;
		for(i = 0; i < E; i++){
			cin >> v >> u >> m;
			adj[v].push_back(make_pair(u, m));
			adj[u].push_back(make_pair(v, m));
		}
		cin >> S;
		q.push(make_pair(0, S));
		memset(vis, 0, sizeof(vis));
        memset(path, 0, sizeof(path));
		while(!q.empty()){
			m = -1 * q.top().first;
			v = q.top().second;
			vis[v] = true;
			path[v] = m;
			q.pop();
            size = adj[v].size();
			for(i = 0; i < size; i++){
                tmp = adj[v][i].first;
				if(!vis[tmp]) q.push(make_pair(-1 * (m + adj[v][i].second), tmp));
            }
			while(!q.empty() && vis[q.top().second] == true) q.pop();
		}
		for(i = 1; i <= V; i++)
			if(i != S){
				if(path[i] != 0) cout << path[i] << " ";
				else cout << -1 << " ";
			}
		cout << endl;
        for(int i = 0; i <= 3001; i++) adj[i].clear();
	}
	return 0;
}
