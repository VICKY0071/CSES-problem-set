#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    cin >> t >> n;
    multiset<int> ticks;
    int cust[n];
    for(int i = 0;i < t;i++){
        int v;
        cin >> v;
        ticks.insert(v);
    }
    for(int i = 0;i < n;i++){
        cin >> cust[i];
    }
    for(int i = 0;i < n;i++){
        auto itr = ticks.upper_bound(cust[i]);
        if(itr == ticks.begin()){
            cout <<-1<<endl;
        }
        else{
            itr--;
            cout <<*itr<<'\n';
            ticks.erase(itr);
        }
    }
    return 0;
}