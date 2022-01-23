#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i= 0;i<n;i++)   cin >> a[i];
    stack<pair<int, int>> st;
    vector<int> res(n);
    for(int i = n -1 ;i>=0;i--){
        while(!st.empty() && st.top().first > a[i]){
            res[st.top().second] = i + 1;
            st.pop();
        }
        st.push({a[i], i});
    }
    while(!st.empty()){
        res[st.top().second] = 0;
        st.pop();
    }
    for(int i : res)    cout <<i<<' ';
    return 0;
}