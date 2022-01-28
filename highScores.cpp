#include <bits/stdc++.h>
#define int long long
using namespace std;

// int p[2501];
int d[2501];

class Edge{
    public:
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<Edge> a(n);
    for(int i = 0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        a[i] = {Edge(u, v, w * -1)};
    }
    const int INF = 1e17;
    const int NINF = (-1) * INF;
    fill(d, d + n, INF);
    // fill(p, p + n, -1);
    d[0] = 0;
    for(int i = 0;i < n - 1;i++){
        for(Edge e : a){
            if(d[e.u] < INF){
                if(d[e.u] + e.w < d[e.v]){
                    d[e.v] = d[e.u] + e.w;
                }
                d[e.v] = max(NINF, d[e.v]); 
            }
        }
    }
    for(int i= 0;i < n - 1; i++){
        for(Edge e : a){
            if(d[e.u] < INF){
                d[e.v] = max(NINF, d[e.v]);
                if(d[e.u] +e.w < d[e.v]){
                    d[e.v] = INF;
                }
            }
        } 
    }
    cout <<(d[n - 1] == INF ? -1 : d[n - 1] * -1)<<endl;
    return 0;
}