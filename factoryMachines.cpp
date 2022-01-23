#include <bits/stdc++.h>
#define int long long
using namespace std;

int k[200001];

bool isValid(int x, int t, int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum += (x / k[i]);
        if(sum >= t)    return true;
    }
    return false;
}

int32_t main(){
    int n, t;
    cin >> n >> t;
    for(int i = 0;i<n;i++)  cin >> k[i];
    int lo = 0;
    int hi = LLONG_MAX;
    while(lo < hi - 1){
        int mid = lo + (hi - lo) / 2;
        if(isValid(mid, t, n)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    for(int i = lo;i<hi;i++){
        if(isValid(i, t, n)){
            cout <<i<<'\n';
            return 0;
        }
    }
    cout<<hi<<endl;
    return 0;
}