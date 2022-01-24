#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, p;
    cin >> s >> p;
    string t = p + "@" + s;
    const int n = t.size();
    int k[n] = {0};
    for(int i = 1, l = 0, r = 0;i < n;i++){
        if(i <= r){
            k[i] = min(r - i + 1, k[i - l]);
        }
        while(i + k[i] < n && t[k[i]] == t[i + k[i]])   k[i]++;
        if(i + k[i] - 1 > r){
            l = i;
            r = i + k[i] - 1;
        }
    }
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(k[i] == p.size()){
            cnt++;
        }
    }
    cout <<cnt<<endl;
    return 0;
}