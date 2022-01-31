#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    int pos[n];
    for(int i = 0;i < n;i++)    cin >> pos[i];
    set<int> st;
    st.insert(1);
    st.insert(x);
    int mx = INT_MIN;
    int mxCnt = 0;
    for(int i = 0;i < n;i++){
        auto up = st.upper_bound(pos[i]);
        // st.insert(ppos[i]);
        int forward = (*up) - pos[i];
        auto back = up;
        back--;
        int backward = pos[i] - (*back);
        
        st.insert(pos[i]);
    } 
    return 0;
}