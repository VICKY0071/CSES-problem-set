#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++)    cin >> a[i];
    multiset<int> st;
    for(int i = 0;i < n;i++){
        auto x = st.upper_bound(a[i]);
        if(x == st.end()){
            st.insert(a[i]);
        }
        else{
            st.erase(x);    
            st.insert(a[i]);
        }
    }
    cout <<st.size()<<endl;
    return 0;
}