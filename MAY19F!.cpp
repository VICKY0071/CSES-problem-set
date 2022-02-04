#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    int dp[n];
    int mx = INT_MIN;
    for(int i = 0;i < n;i++){
        int v;
        cin >> v;
        dp[i] = mx = max(mx, v);
    }
    for(int i = 0;i < q;i++){
        int v;
        cin >> v;
        cout <<dp[v - 1]<<endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}