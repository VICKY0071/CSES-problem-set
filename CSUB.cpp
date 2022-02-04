#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ones = 0;
    for(int i = 0;i < n;i++)    ones += (s[i] == '1');
    cout <<(ones * (ones + 1)) / 2<<endl;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}