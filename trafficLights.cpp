#include <bits/stdc++.h>

using namespace std;


class Pair{
    public:
    int first, second;
    Pair(){}
    Pair(int p, int s){
        first = p;
        second = s;
    }
    friend ostream& operator << (ostream& os, const Pair& temp);
};


class Compare{
    bool operator() (const int& a, const int& b){
        return a < b;
    }
    bool operator() (const Pair& a, const Pair& b){
         return (a.second - a.first) < (b.second - b.first);
    }
};

ostream& operator << (ostream& os, const Pair& temp){
    os << temp.second - temp.first <<endl;
    return os;
}

int main(){
    int x, n;
    cin >> x >> n;
    set<int> st;
    st.insert(1);
    st.insert(x);
    set<Pair> pr;
    Pair l = Pair(1, x);
    pr.insert(Pair(1, x));
    for(int i = 0;i < n;i++){
        int v;
        cin >> v;
        st.insert(v);
        auto x = st.find(v);
        auto behind = x, ahead = x;
        ahead++;
        behind--;
        // pr.erase(Pair(*behind, *ahead));
        // pr.insert(Pair(*behind, v));
        // pr.insert(Pair(i, *ahead));
        // cout << *pr.rbegin()<<endl;
    }

}   