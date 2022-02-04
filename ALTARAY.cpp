#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int res[n];
    vector<int> a(n);
    for(int i = 0; i < n;i++)   cin >> a[i];
    int i = 0;
    int j = 0;
    while(i < n){
        j = i + 1;
        while(j < n && ((a[j] < 0 && a[j - 1] >= 0) || (a[j] >= 0 && a[j - 1] < 0))){
            j++;
        }
        int cnt = j - i;
        for(int k = i;k < j;k++){
            res[k] = cnt--;
        }
        i = j;
    }
    for(int i = 0;i < n;i++)    cout <<res[i]<<" ";
    cout <<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}