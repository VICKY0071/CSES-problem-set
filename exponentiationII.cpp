#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

int solve(int a, int b, int MOD){
    if(b == 0)  return 1;
    int ele = 1;
    a %= MOD;
    if(a == 0)  return 0;
    while(b > 0){
        if((b & 1)){
            ele = (ele * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ele;
}

int32_t main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        cout <<solve(a, solve(b, c, mod - 1), mod)<<endl;
    }
    return 0;
}