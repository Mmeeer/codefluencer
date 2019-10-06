#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
// minimum spannin treeg bodoh 2 algorithm
// ene ni prim gdg algorihm ba ta buhen netees yaaj ajilladgagiig haraarai.
// kruskal-iin algorithm ch baij magadgui ug ni bodlogo ni kruskal-aar bod gsn bn
// bi primeer bodchihson bololtoi hhha.
// https://www.hackerrank.com/challenges/kruskalmstrsub/problem
using namespace std;
vector<pair<int, int> > adj[3001];
priority_queue<pair<int, int> > pq;
bool vis[3001];
int N, M, S;
void init(){
	int v, u, m;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> v >> u >> m;
		adj[v].push_back(make_pair(u, m));
		adj[u].push_back(make_pair(v, m));
	}
	cin >> S;
	vis[S] = true;
	v = adj[S].size();
	for(int i = 0; i < v; i++) pq.push(make_pair(-1 * adj[S][i].second, adj[S][i].first));
}
long long prim(){
	long long s = 0;
	int v, m, size;
	while(!pq.empty()){
		m = -1 * pq.top().first;
		v = pq.top().second;
		pq.pop();
		vis[v] = true;
		s += m;
		size = adj[v].size();
		for(int i = 0; i < size; i++){
			if(!vis[adj[v][i].first]) pq.push(make_pair(-1 * adj[v][i].second, adj[v][i].first));
		}
		while(!pq.empty() && vis[pq.top().second] == true) pq.pop();
	}
	return s;
}
int main(){
	init();
	cout << prim();
	return 0;
}
