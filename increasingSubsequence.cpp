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
    set<int> st;
    int res = 0;
    for(int i = n - 1;i >= 0;i--){
        if(st.count(a[i]) == 0){
            st.insert(a[i]);
            auto x = st.find(a[i]);
            st.erase(st.begin(), x);
            res = max(res, (int)st.size());
        }
    }
    cout <<res<<endl;
    return 0;
}