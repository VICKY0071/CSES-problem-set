#include <bits/stdc++.h>

using namespace std;

set<string> st;

void permute(string& s, int lo, int hi){
    if(lo == hi){
        st.insert(s);
    }
    else{
        for(int i = lo;i<=hi;i++){
            swap(s[lo], s[i]);
            permute(s, lo + 1, hi);
            swap(s[lo], s[i]);
        }
    }
}

int main(){
    string s;
    cin >> s;
    permute(s, 0, s.size() - 1);
    cout <<st.size()<<endl;
    for(auto i : st){
        cout <<i<<'\n';
    }
    return 0;
}