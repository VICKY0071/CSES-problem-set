#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> zString(string& s){
    const int n = s.size();
    vector<int> z(n, 0);
    for(int i = 1, l= 0, r = 0;i < n;i++){
        if(i <= r){
            z[i] = min(r - i + 1, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[z[i] + i])   z[i]++;
        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int32_t main(){
    string s;
    cin >> s;
    const int n = s.size();
    vector<int> z = zString(s);
    vector<int> lis(n, 0);
    int i = 0;
    int j = 1;
    while(i < j && j < n){
        if(s[i] == s[j]){
            lis[j] = i + 1;
            i++, j++;
        }
        else{
            if(i == 0){
                lis[j] = 0;
                j++;
            }
            else{
                i = lis[i - 1];
            }
        }
    }
    for(int i : z)  cout <<i<<' ';
    cout <<endl;
    for(int i = 0;i<n;i++){
        cout <<lis[i]<<' ';
    }
    return 0;
}