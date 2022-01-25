#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i = 0;i<n;i++){
        cin >> a[i][1] >> a[i][0];
        a[i][2] = i;
    }
    auto compare = [](vector<int>& a, vector<int>& b){
        return a[1] != b[1] ? a[1] < b[1] : (a[0] != b[0] ? a[0] < b[0] : a[2] < b[2]);
    };
    sort(a.begin(), a.end(), compare);
    int itContains[n] = {0}, containsIt[n] = {0};
    multiset<int> st;
    // for(int i = 0;i<n;i++){
    //     cout <<a[i][1]<<" "<<a[i][0]<<",";
    // }
    // cout <<endl;
    for(int l = 0;l < n;l++){
        auto x = upper_bound(a.begin() + l, a.end(), vector<int>{a[l][0], LLONG_MIN, LLONG_MIN});
        // if(x == a.end())    cout <<"YES\n";
        // x--;
        // x--;
        // cout <<(*x)[1]<<' '<<(*x)[0]<<"->"<<x - a.begin()<<endl;
        int v = (x - a.begin()) - l;
        int t = st.size() - distance(st.begin(), st.lower_bound(a[l][0]));
        // cout <<v<<' '<<a[l][2]<<endl;
        st.insert(a[l][0]);
        itContains[a[l][2]] = v;
        containsIt[a[l][2]] = t;
    }
    for(int i = 0;i<n;i++){
        cout <<itContains[i]<<' ';
    }
    cout <<endl;
    for(int i = 0;i<n;i++){
        cout <<containsIt[i]<<' ';
    }
    return 0;
}