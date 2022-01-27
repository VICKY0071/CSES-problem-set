#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int, int>> a[100001];

int32_t main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        a[u].push_back({v, w});
        // a[v].push_back({u, w});
    }
    int dis[n];
    fill(dis, dis + n, LLONG_MAX);
    dis[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});  
    while(!q.empty()){
        auto temp = q.top();
        q.pop();
        int d = temp.second;
        for(auto& i : a[d]){
            int newDistance = dis[d] + i.second;
            if(newDistance < dis[i.first]){
                dis[i.first] = newDistance;
                q.push({newDistance, i.first});
            }
        }
    }
    for(int i = 0;i<n;i++){
        cout << dis[i] <<' ';
    }
    cout <<endl;
    return 0;
}