#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int b[n], p[n];
    for(int i = 0;i < n;i++)   cin >> b[i];
    for(int i = 0;i < n;i++)    cin >> p[i];
    priority_queue<pair<double, pair<int, int>>> q;
    for(int i = 0;i < n;i++){
        q.push({(p[i] / (b[i] * 1.0)), {b[i], p[i]}});
    }
    int res= 0;
    while(!q.empty() && m > 0){
        auto temp = q.top();
        q.pop();
        if(m >= temp.second.first){
            res += temp.second.second;
            m -= temp.second.first;
        }
    }
    cout <<res<<endl;
    return 0;
}