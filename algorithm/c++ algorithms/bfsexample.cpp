#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
// harj baigaachlan ene hesegt vector queue ashiglasan baigaa.
// mun vector oo husnegt helbereer davharlaj uusegsen ni 2 hemjeest husnegt bolgoj ugj baigaa yum.
// https://www.hackerrank.com/challenges/bfsshortreach/problem
using namespace std;
int ans[1001], n, m, s, p;
bool vis[1001];
vector<int> adj[1001];
queue<int> q;
void init(){
	cin >> n >> m;
	int x, y;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> p;
	q.push(p);
	vis[p] = true;
	ans[p] = s;
}
void bfs(){
	if(q.empty()) return;
	s++;
	int size = q.size();
	while(size--){
		int x = q.front(), sizer = adj[x].size();
		q.pop();
		for(int i = 0; i < sizer; i++){
			if(!vis[adj[x][i]]){
				q.push(adj[x][i]);
				vis[adj[x][i]] = true;
				ans[adj[x][i]] = s;
			}
		}
	}
	bfs();
}
void clean(){
	for(int i = 1; i < n+1; i++){
		adj[i].clear();
		vis[i] = 0;
		ans[i] = 0;
	}
	s = 0;
}
void out(){
	for(int i = 1; i <= n; i++){
		if(vis[i] && p != i) cout << ans[i]*6 << " ";
		else if(!vis[i]) cout << "-1 ";
	}
	cout << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		init();
		bfs();
		out();
		clean();
	}
	return 0;
}
