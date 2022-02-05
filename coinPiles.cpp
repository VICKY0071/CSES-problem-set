#include <bits/stdc++.h>
#define int long long
using namespace std;

bool solve(int a,int b){
    if((a == b && b == 0) || ((a >> 1) == b || (b >> 1) == a)){
        return true;
    }
    if(a <  1|| b < 1)  return false;
    return solve(a - 2, b - 1) || solve(a - 1, b - 2);
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout <<(solve(a, b) ? "YES\n" : "NO\n");;
    }
    return 0;
}