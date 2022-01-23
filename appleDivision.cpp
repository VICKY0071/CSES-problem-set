#include <bits/stdc++.h>
#define int long long
using namespace std;

int diff = LLONG_MAX;

void solve(int a[], int n, int idx, int s1 = 0, int s2 = 0){
    if(idx == n){
        diff = min(diff, abs(s1 - s2));
        return;
    }
    else{
        solve(a, n, idx + 1, s1 + a[idx], s2);
        solve(a, n, idx + 1, s1, s2 + a[idx]);
    }
}

int solve(int a[], int n){
    int x = pow(2, n);
    int res = INT_MAX;
    for(int i = 0;i<x;i++){
        int lastIndex = n - 1;
        int s1 = 0, s2 = 0;
        for(int j = i;j > 0 && lastIndex >= 0;j >>= 1, lastIndex--){
            if((j & 1) == 1)  s1 += a[lastIndex];
            else    s2 += a[lastIndex];
        }
        while(lastIndex >= 0){
            s2 += a[lastIndex--];
        }
        res = min(res, abs(s2 - s1));
    }
    return res;
}

int32_t main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i<n;i++)  cin >> a[i];
    // solve(a, n, 0);
    // cout <<diff<<endl;
    cout <<solve(a, n)<<endl;
    return 0;
}