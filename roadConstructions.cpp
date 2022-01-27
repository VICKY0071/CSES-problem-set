#include <bits/stdc++.h>

using namespace std;

int par[100001];
int sz[100001];

int bestSize = 0;
int comp;

int _find(int x){
    if(x == par[x]) return x;
    return par[x] = _find(par[x]);
}

int merge(int u, int v){
    u = _find(u), v= _find(v);
    if(u != v){
        comp--;
        if(sz[v] > sz[u]){
            swap(u, v);
        }
        sz[u] += sz[v];
        if(sz[u] > bestSize){
            bestSize = sz[u];
        }
        par[v] = u;
    }
    return bestSize;
}

int main(){
    int n , m;
    cin >> n >> m;
    comp = n;
    for(int i = 0;i<n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        int x = merge(u, v);
        cout <<comp<<' '<<x<<endl;
    }
    return 0;
}