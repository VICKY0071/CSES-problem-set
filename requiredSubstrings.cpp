#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int op(int b){
    int res = 1;
    int v = 26;
    while(b > 0){
        if(b & 1){
            res = (res * v) % MOD;
        }
        b >>= 1;
        v = (v * v) % MOD;
    }
    return res;
}

int32_t main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = s.size();
    if(m > n)   cout <<0<<'\n';
    else if(n == m) cout <<1<<endl;
    else{
        int diff = (n - m);
        int sum = 0;
        cout <<diff<<endl;
        int x = op(diff);
        sum = ((diff >> 1) + 1) * ((2 * x) % MOD);
        cout <<sum<<endl;
        if(n % 2 == 0)  sum -= x;
        cout <<sum<<endl;
    }
    return 0;
}