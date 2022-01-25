#include <bits/stdc++.h>
#define int long long
using namespace std;

int colors[100001];
int head[100001];

vector<int> order;
void dfs1(vector<vector<int>>& a, int i){
    colors[i] = 1;
    for(int x : a[i]){
        if(colors[x] == 0){
            dfs1(a, x);
        }
    }
    order.push_back(i);
}

void dfs2(vector<vector<int>>& a, int i, int rep){
    head[i] = rep;
    colors[i] = 0;
    for(int x : a[i]){
        if(colors[x] == 1){
            dfs2(a, x, rep);
        }
    }
}


int32_t main(){
    int n, m;
    cin >> n >> m;
    memset(head, -1, sizeof head);
    memset(colors, 0, sizeof colors);
    vector<vector<int>> a(n);
    vector<vector<int>> rev(n);
    for(int i = 0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        a[u].push_back(v);
        rev[v].push_back(u);
    }
    for(int i = 0;i<n;i++){
        if(colors[i] == 0){
            dfs1(a, i);
        }
    }
    // for(int i = 0;i<n;i++){
    //     for(int j : a[i]){
    //         rev[j].push_back(i);
    //     }
    // }
    for(int i = order.size() - 1;i >= 0;i--){
        if(colors[order[i]] == 1){
            dfs2(rev, order[i], order[i]);
        }
    }
    int id = 0;
    int ans[n];
    unordered_map<int, int> idx;
    for(int i = 0;i<n;i++){
        if(idx[head[i]] == 0){
            idx[head[i]] = ++id;
        }
        ans[i] = idx[head[i]];
    }
    cout <<id<<endl;
    for(int i = 0;i<n;i++){
        cout <<ans[i]<<' ';
    }
    return 0;
}