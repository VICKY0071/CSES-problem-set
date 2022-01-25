#include <bits/stdc++.h>

using namespace std;

int colors[200001];
int head[200001];

vector<int> order;
void dfs1(vector<vector<int>>& a, int i){
    colors[i] = 1;
    for(int x : a[i]){
        if(colors[i] == 0){
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

int main(){
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
    
    return 0;
}