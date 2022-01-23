#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200001];
int32_t main(){
    int n;
    cin >> n;
    int ans = 0;
    map<int, int> x;
    for(int i = 0;i<n;i++){
        int v;
        cin >> v;
        x[v] = i;
    }
    for(auto itr = x.begin();itr != x.end();itr++){
        if(itr->second != -1){
            auto itr2 = itr;
            advance(itr2, 1);
            ans++;
            while(itr2 != x.end()){
                if(itr2->second > itr->second){
                    x[itr2->first] = -1;
                }
                itr2++;
            }
        }
    }
    cout <<ans<<endl;
    return 0;
}