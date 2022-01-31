#include <bits/stdc++.h>

using namespace std;

bool vis[1000001];

void dfs(vector<int> a[], int x){
	vis[x] = true;
	for(auto i : a[x]){
		if(!vis[i]){
			dfs(a, i);
		}
	}
}

int d[1000001];
vector<int> path;
void dfs2(vector<int> a[], int x){
	// vis[x] = true;
	while(d[x] < a[x].size()){
		a[a[x][d[x]]].erase(find(a[a[x][d[x]]].begin(), a[a[x][d[x]]].end(), x));
		dfs2(a, a[x][d[x]++]);
		// else	d[x]++;
	}
	path.push_back(x);
}

int main(){	
	int n, m;
	cin >> n >> m;
	memset(d, 0, sizeof(int) * n);
	fill(vis, vis + n, false);
	vector<int> a[n];
	for(int i = 0; i < m;i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		a[u].push_back(v);
		a[v].push_back(u); 	
	}
	dfs(a, 0);
	bool invalid = false;
	for(int i = 0;i < n;i++){
		if(!vis[i] && a[i].size() == 0)	continue;
		if(!vis[i] || (a[i].size() % 2 != 0)){
			invalid = true;
			break;
		}
	}
	if(invalid){
		cout <<"IMPOSSIBLE\n";
	}	
	else{
		dfs2(a, 0);
		for(int i: path)	cout <<i + 1<<' ';
	}
	return 0;
}