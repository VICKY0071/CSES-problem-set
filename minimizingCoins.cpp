#include <bits/stdc++.h>
#define int long long
using namespace std;

int coins[1000001];

int32_t main(){
    int n, x;
    cin >>  n >> x;
    int c[n];
    const int INF = 1e9;
    for(int i = 0;i < n;i++)    cin >> c[i];
    fill(coins, coins + 1000001, INF);
    coins[0] = 0;
    for(int i = 1; i <= x;i++){
        for(int j = 0;j < n;j++){
            if(i - c[j] >= 0)   coins[i] = min(coins[i], coins[i - c[j]] + 1);
        }
    }
    cout <<(coins[x] == INF ? -1 : coins[x])<<endl;
    return 0;
}
