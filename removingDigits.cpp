#include <bits/stdc++.h>

using namespace std;

int getMax(int n){
    string s = to_string(n);
    int mx = -1;
    for(int i = 0;i<s.size();i++){
        mx = max(mx, stoi(s[i] + string()));
    }
    return mx;
}
int main(){
    int n;
    cin >> n;
    int cnt = 0 ;
    while(n > 0){
        int mx = getMax(n);
        n -= mx;
        cnt++;
    }
    cout <<cnt<<endl;
    return 0;
}