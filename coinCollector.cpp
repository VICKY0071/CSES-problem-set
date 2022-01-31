#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n, m;
    cin >> n >> m;
    int cost[n];
    for(int i = 0;i  <n;i++){
        cin >> cost[i];
    }
    vector<int> a[n];
    vector<int> rev[n];
    for(int i = 0;i < m;i++){
        int u, v;
        cin >>u >> v;
        u--, v--;
        a[u].push_back(v);
        rev[v].push_back(u);
    }
    
    return 0;
}