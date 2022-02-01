#include <bits/stdc++.h>
#define int long long
using namespace std;

int f[200001];
int g[200001];
vector<int> a[200001];
int res;

void dfs(vector<int> a[], int idx, int par){
    vector<int> cb;
    for(int i : a[idx]){
        if(i != par){
            dfs(a, i, idx);
            f[idx] = max(f[idx], f[i] + 1);
            cb.push_back(f[i]);
        } 
    }
    res = max(res, f[idx]);
    
    sort(cb.begin(), cb.end());
    if(cb.size() >= 2){
        g[idx] = 2 + cb[cb.size() - 1] + cb[cb.size() - 2];
        res = max(res, g[idx]);
    }
}

int32_t main(){
    int n;
    cin >> n;
    for(int i = 0;i < n - 1;i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(a, 1, -1);
    cout <<res<<endl;
    return 0;
}