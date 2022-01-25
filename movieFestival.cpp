#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for(int i = 0;i<n;i++){
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());
    int l = 0;
    int r = 1;
    int cnt = 0;
    while(l < n && r < n){
        if(l == r)  r += 1;
        if(a[r][0] < a[l][1]){
            if(a[r][1] < a[l][1]){
                l++;
            }
            else{
                r++;
            }
        }
        else{
            l++;
            r++;
        }
        cnt++;
    }
    cout <<cnt<<endl;
    return 0;
}