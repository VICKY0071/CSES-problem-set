#include <bits/stdc++.h>
#define int long long
using namespace std;

int colors[200001];
int head[200001];

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

int v, d;
void dfs(unordered_map<int, int>& cnt, vector<vector<int>>& a, int src){
    if(cnt[head[src]] != 1 || (cnt[head[src]] == 1 && a[src][0] == src)){
        v = cnt[head[src]];
        return;
    }
    dfs(cnt, a, a[src][0]);
    d++;
    cnt[head[src]] = d + v;
}

int32_t main(){
    int n;
    cin >> n;
    memset(head, -1, sizeof head);
    memset(colors, 0, sizeof colors);
    vector<vector<int>> a(n);
    vector<vector<int>> rev(n);
    for(int i = 0;i<n;i++){
        int v;
        cin >> v;
        v -= 1;
        a[i].push_back(v);
        rev[v].push_back(i);
    }
    for(int i = 0;i<n;i++){
        if(colors[i] == 0){
            dfs1(a, i);
        }
    }

    for(int i = order.size() - 1;i >= 0;i--){
        if(colors[order[i]] == 1){
            dfs2(rev, order[i], order[i]);
        }
    }
    vector<int> ans(n);
    unordered_map<int, int> cnt;
    for(int i = 0;i<n;i++)  cnt[head[i]]++;
    for(int i = 0;i<n;i++){
        if(cnt[head[i]] == 1){
            if(a[i][0] == i ){
                ans[i] = 1;
            }
            else{
                d=  0;
                dfs(cnt, a, i);
                ans[i] = cnt[head[i]];
            }
        }
        else{
            ans[i] = cnt[head[i]];
        }
    }
    for(int i : ans)    cout <<i<<' ';
    return 0;
}