#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0;i<n;i++)  cin >> a[i];
    int sum = 0;
    int j = 0;
    int ans = 0;
    for(int i = 0;i<n;i++){
        sum += a[i];
        while(j <= i && sum > x){
            sum -= a[j];
            j++;
        }
        if(sum == x){
            ans++;
        }
    }
    cout <<ans<<endl;
    return 0;
}