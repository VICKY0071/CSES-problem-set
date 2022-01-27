#include <bits/stdc++.h>

using namespace std;

vector<int> a[100001];
bool vis[100001];
int par[100001];

int main(){
    int n, m;
    cin >> n >> m;
    memset(par, -1, sizeof par);
    for(int i = 0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    queue<int> q;
    q.push(0);
    bool reached = false;
    vis[0] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(t == n - 1){
            reached = true;
            break;
        }
        for(int i : a[t]){
            if(!vis[i]){
                par[i] = t;
                q.push(i);
                vis[i] = true;
            }
        }
    }
    if(!reached)    cout <<"IMPOSSIBLE\n";
    else{
        vector<int> a;
        int x = n -1;
        while(x != 0){
            a.push_back(x + 1);
            x = par[x];
        }
        a.push_back(1);
        cout <<a.size()<<endl;
        for(int i = a.size() - 1;i >= 0;i--)    cout <<a[i]<<" ";
    }
    return 0;
}