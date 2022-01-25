#include <bits/stdc++.h>
#define int long long
using namespace std;

int colors[2000001];
int head[2000001];

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
    // cout <<src<<endl;
    if(cnt[src] != 1 || (cnt[src] == 1 && a[src][0] == src)){
        v = cnt[src];
        return;
    }
    // cout <<src<<endl;
    dfs(cnt, a, a[src][0]);
    d++;
    cnt[src] = d + v;
}

int32_t main(){
    int n;
    cin >> n;
    memset(head, -1, sizeof head);
    vector<vector<int>> a(n);
    for(int i = 0;i<n;i++){
        int v;
        cin >> v;
        v -= 1;
        a[i].push_back(v);
    }
    for(int i = 0;i<n;i++){
        if(colors[i] == 0){
            dfs1(a, i);
        }
    }
    vector<vector<int>> rev(n);
    for(int i = 0;i<n;i++){
        for(int j : a[i]){
            rev[j].push_back(i);
        }
    }
    for(int i = order.size();i >= 0;i--){
        if(colors[i] == 1){
            dfs2(rev, i, i);
        }
    }
    // for(int i = 0;i<n;i++)  cout <<head[i]<<' ';
    // cout <<endl;
    unordered_map<int, int> cnt;
    for(int i = 0;i<n;i++){
        cnt[head[i]]++;
    }
    for(int i = 0;i<n;i++){
        cnt[i] = cnt[head[i]];
    }
    // for(auto i : cnt){
    //     cout <<i.first<<"->"<<i.second<<endl;
    // }
    vector<int> ans(n);
    for(int i = 0;i<n;i++){
        if(cnt[i] == 1){
            if(a[i][0] == i){
                ans[i] = 1;
            }
            else{
                dfs(cnt, a, i);
                ans[i] = cnt[i];
            }
        }
        else{
            ans[i] = cnt[head[i]];
        }
    }
    // for(auto i : cnt){
    //     cout <<i.first<<"->"<<i.second<<endl;
    // }
    for(int i : ans){
        cout<<i<<' ';
    }
    return 0;
}