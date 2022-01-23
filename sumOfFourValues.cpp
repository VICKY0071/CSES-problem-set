#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n, t;
    cin >> n >> t;
    int a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    unordered_map<int, set<pair<int, int>>> pr;
    for(int i = 0;i<n - 1;i++){
        for(int j = i + 1;j < n;j++){
            pr[a[i] + a[j]].insert({i, j});
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = i + 1;j < n;j++){
            if(pr.count(t - (a[i] + a[j])) > 0){
                auto x = pr[t - (a[i] + a[j])].lower_bonf;
                if(x.first != i && x.first != j && x.second != i && x.second != j){
                    cout <<i + 1<<' '<<j + 1<<' '<<x.first + 1<<' '<<x.second + 1<<endl;
                    return 0;
                }
            }
        }
    }
    cout <<"IMPOSSIBLE\n";
    return 0;
}