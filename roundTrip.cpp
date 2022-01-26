#include <bits/stdc++.h>
#define int long long
using namespace std;

int colors[100001];
int par[100001];
vector<int> ans;
vector<pair<int, int>> cycles;

vector<int> getSize(int start, int end){
    int i = end;
    vector<int> res;
    while(i != start){
        res.push_back(i);
        i = par[i];
    }
    res.push_back(start);
    res.push_back(end);
    reverse(res.begin(), res.end());
    return res;
}

void dfs(vector<vector<int>>& a, int idx){
    if(ans.size() >= 4) return;
    colors[idx] = 1;
    for(int i: a[idx]){
        if(colors[i] == 0){
            par[i] = idx;
            dfs(a, i);
        }
        else if(colors[i] == 1){
            if(ans.size() < 4){
                ans = getSize(i, idx);
            }
        }
    }
    colors[idx] = 2;
}

int32_t main(){
    int n, m;
    cin >> n >> m;
    fill(par, par + n, -1);
    vector<vector<int>> a(n);
    for(int i = 0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 0;i<n;i++){
        if(colors[i] == 0){
            dfs(a, i);
        }
    }
    if(ans.size()  < 4 || ans.empty()){
        cout <<"IMPOSSIBLE\n";
    }
    else{
        cout <<ans.size()<<endl;
        for(int i : ans)    cout <<i + 1<<' ';
    }
    return 0;
}