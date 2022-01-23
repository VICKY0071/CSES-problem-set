#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    vector<int> lis;
    for(int i = 0;i<n;i++){
        auto x = lower_bound(lis.begin(), lis.end(), a[i]);
        if(x == lis.end()){
            lis.push_back(a[i]);
        }
        else{
            *x = a[i];
        }
    }
    cout <<lis.size()<<endl;
    return 0;
}