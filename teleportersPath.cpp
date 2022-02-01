#include <bits/stdc++.h>

using namespace std;

int in[100001];
int out[100001];
bool vis[100001];

void dfs(vector<int> a[], int x){
    vis[x] = true;
    for(int i : a[x]){
        if(!vis[i]){
            dfs(a, i);
        }
    }
}

vector<int> path;
void findPath(vector<int> a[], int start, int end){
    while(out[start] != 0){
        findPath(a, a[start][--out[start]], end);
    }
    path.push_back(start);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a[n];
    
    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >>v;
        u--, v--;
        a[u].push_back(v);
        in[v]++;
        out[u]++;
    }

    int disrupt = 0;
    int io = 0, oi = 0;
    int start, end;
    for(int i = 0;i < n;i++){
        if(in[i] - out[i] == 1){
            io++;
            end = i;
        }
        else if(out[i] - in[i] == 1){
            oi++;
            start = i;
        }
        else if(in[i] - out[i] != 0){
            disrupt++;
        }
    }
    if(io == 1 && oi == 1 && start == 0 && end == n -1 && disrupt == 0){
        fill(vis, vis + n, false);
        dfs(a, start);   
        for(int i = 0;i < n;i++){
            if(vis[i] == false && (in[i] != 0 || out[i] != 0)){
                cout <<"IMPOSSIBLE\n";
                return 0;
            }
        }
        findPath(a, start, end);
        for(int i = path.size() - 1;i >= 0;i--){
            cout <<path[i] + 1<<' ';
        }
    }
    else{
        cout <<"IMPOSSIBLE\n";
    }
    return 0;
}