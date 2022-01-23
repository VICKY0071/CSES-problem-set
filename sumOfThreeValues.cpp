#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector<vector<int>> a(n, vector<int>(2));
    for(int i = 0;i<n;i++){
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a.begin(), a.end());
    for(int i = 0;i < n - 2;i++){
        int l = i + 1;
        int r = n - 1;
        while(l < r){
            int sum = a[l][0] + a[r][0];
            if(sum == (t - a[i][0])){
                cout <<a[i][1] + 1<<" "<<a[l][1] + 1<<" "<<a[r][1] + 1<<endl;
                return 0;
            }
            if(sum > (t - a[i][0])){
                r--;
            }
            else{
                l++;
            }
        }
    }
    cout <<"IMPOSSIBLE\n";
    return 0;
}