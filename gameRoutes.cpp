#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

bool vis[100001];
vector<int> v;
int dp[100001];
unordered_map<int, vector<int>> par;

void dfs(vector<vector<int>>& a, int idx, int p){
    vis[idx] = true;
    if(p != -1) par[idx].push_back(p);
    for(int i : a[idx]){
        if(!vis[i]){
            dfs(a, i, idx);
        }
        else{
            par[i].push_back(idx);
        }
    }
    v.push_back(idx);
}

int main(){
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof dp);
    vector<vector<int>> a(n);
    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
 
        u--, v--;
        a[u].push_back(v);
    }
    dfs(a, 0, -1);
    reverse(v.begin(), v.end());
    
    dp[v[0]] = 1;

    for(int i = 1;i < v.size();i++){
        for(int j : par[v[i]]){
            dp[v[i]] = ((dp[v[i]] %  MOD) + dp[j]) % MOD;
        }
        if(v[i] == n - 1)  break;
    }
    cout <<dp[n - 1]<<endl;
    return 0;
}