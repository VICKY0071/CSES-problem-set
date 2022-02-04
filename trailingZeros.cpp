#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    int x = 5;
    int ans = 0;
    while((n / x) > 0){
        ans += (n / x);
        x *= 5;
    }
    cout <<ans<<endl;
    return 0;
}
