#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    const int n = s.size();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0;i < n;i++){
        if(i <= r){
            z[i] = min(r - i + 1, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    vector<int> res;
    for(int i = 0;i<n;i++){
        if(n - i == z[i]){
            res.push_back(z[i]);
        }   
    }
    for(int i = res.size() - 1;i >= 0;i--){
        cout <<res[i]<<' ';
    }
    cout <<endl;
    return 0;
}