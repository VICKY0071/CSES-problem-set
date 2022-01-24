#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200001];

bool valid(int x, int n, int k){
    int parts=  0;
    int sum = 0;
    for(int i = 0;i<n;i++){
        if(a[i] > x)    return false;
        sum += a[i];
        if(sum > x){
            sum = a[i];
            parts++;
        }
    }
    return (parts + 1 ) <= k;
}

int32_t main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0;i<n;i++)  cin >> a[i];
    int lo = 0;
    int hi = LLONG_MAX;
    while(lo < hi - 1){
        int mid = lo + (hi - lo) / 2;
        if(valid(mid, n, k)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    for(int i = lo;i<hi;i++){
        if(valid(i, n, k)){
            hi = i;
            break;
        }
    }
    cout <<hi<<endl;
    return 0;
}