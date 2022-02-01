#include <bits/stdc++.h>

using namespace std;

int res[200001];
vector<int> a[200001];

int dfs(int idx){
    if(a[idx].size() == 0){
        return 1;
    }
    int v = 0;
    for(int x : a[idx]){
        v += dfs(x);
    }
    res[idx] = v;
    return v + 1;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1;i < n;i++){
        int v;
        cin >> v;
        a[v - 1].push_back(i);
    }
    dfs(0);
    for(int i = 0;i < n;i++){
        cout <<res[i]<<' ';
    }
    return 0;
}