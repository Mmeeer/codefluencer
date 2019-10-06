#include<iostream>
#include<vector>
// dfs ni shuud asuudliig shiideh shiidel boldoggui baa huvirgah zamaar bodlogiig boddog.
// ene bodlogo ni even tree gdg bodlogo ba dfs-iig huvirgan bodson baigaa
// https://www.hackerrank.com/challenges/even-tree/problem
using namespace std;
int N, M, ans;
vector<int> adj[101];
void init(){
	int v, u;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
}
int dfs(int rec, int now){
	int size = adj[now].size(), sum = 0;
	for(int i = 0; i < size; i++){
		if(adj[now][i] != rec){
			sum += dfs(now, adj[now][i]) + 1;
		}
	}
	if(sum % 2 == 1) ans++;
	return sum;
}
int main(){
	init();
	dfs(0, 1);
	cout << ans - 1;
}
