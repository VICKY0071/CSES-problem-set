#include <bits/stdc++.h>
#define int long long
using namespace std;

int parent[100001];
int size[100001];

int _find(int x){
    if(x == parent[x])  return x;
    return parent[x] = _find(parent[x]);
}

void merge(int u, int v){
    u = _find(u);
    v = _find(v);
    if(u != v){
        if(size[v] > size[u]){
            swap(u, v);
        }
    }
    parent[v] = u;
    size[u] += size[v];
}

int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    for(int i = 0;i<n;i++){
        parent[i] = i;
        size[i] = 1;
    }
    for(int i = 0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        a[i] = {u, v, w};
    }
    auto compare = [](vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    };
    sort(a.begin(), a.end(), compare);
    int bestSum = 0;
    int edges = 0;
    int idx = 0;
    while(idx < m && edges < n - 1){
        auto temp = a[idx++];
        int u = _find(temp[0]);
        int v = _find(temp[1]);
        if(u == v){
            continue;
        }
        edges++;
        merge(u, v);
        bestSum += temp[2];
    }
    if(edges != n - 1){
        cout <<"IMPOSSIBLE\n";
    }
    else    cout <<bestSum<<endl;
    return 0;
}