#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string s;
    cin >> s;
    const int n = s.size();
    vector<int> z(n, 0);
    for(int i = 1, l = 0, r = 0;i < n;i++){
        if(i <= r){
            z[i] = min(r - r + 1, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])   z[i]++;
        if(i + z[i] - 1 > r){
            r = i + z[i] - 1;
            l = i;
        }
    }
    unordered_map<int, int> x;
    for(int i = 0;i<n;i++){
        // cout<<i<<endl;
        if(n - i == z[i]){
            x[z[i]] = 1;
            cout <<i<<' ';
        }
        else if(x.count(z[i]) == 0 && z[i] > 0){
            x[z[i]] = 1;
            int l = i;
            while(l < n && z[l] == z[i]){
                l += z[i];
            }
            if(l >= n){
                cout <<z[i]<<' ';
            }
        }
    }
    cout <<n<<endl;
    return 0;
}