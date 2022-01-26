#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    set<int> st;
    int res = 0;
    vector<int> rr;
    int maxCount = 0;
    for(int i= 0;i<n;i++){
        int v;cin >> v;
        st.insert(v);
        auto p = st.upper_bound(v);
        if(p == st.end()){
            res = max(res, x - v);
        }
        p--;
        if(p == st.begin()){
            res = max(res, v - x);
        }
        if(p != st.begin()){
            auto b = p;
            b--;
            res =max(res, v - *b);
        }
        if(p != st.end()){
            auto b = p;
            b++;
            res = max(res, *b - v);
        }
        rr.push_back(res);
    }
    for(int i : rr)    cout <<i<<' ';
    return 0;
}