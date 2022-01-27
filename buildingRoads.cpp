#include <bits/stdc++.h>

using namespace std;

// vector<int> a[100001];
int par[100001];
int sz[100001];

int _find(int x){
    if(par[x] == x)  return x;
    return par[x] = _find(par[x]);
}

void merge(int u, int v){
    u = _find(u);
    v = _find(v);
    if(u != v){
        if(sz[v] > sz[u])   swap(u, v);
    }
    par[v] = par[u];
    sz[u] += sz[v];
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n;i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        merge(u, v);
        // a[u].push_back(v);
        // a[v].push_back(u);
    }
    set<int> x(par, par + n);
    cout <<x.size() - 1<<endl;
    for(auto i : x) cout <<i<<' ';
    return 0;
}