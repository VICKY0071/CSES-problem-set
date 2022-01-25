#include <bits/stdc++.h>
#define int long long 
using namespace std;
 
int32_t main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i = 0;i<n;i++){
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());
    vector<int> rooms;
    int room = 1;
    vector<int> ans(n);
    ans[a[0][2]] = 1;
    rooms.push_back(a[0][1]);
    for(int i = 1;i<n;i++){
        int j = 0;
        for(;j < rooms.size() && rooms[j] >= a[i][0];j++);
        if(j == rooms.size()){
            room++;
            rooms.push_back(a[i][1]);
        }
        else{
            rooms[j] = a[i][1];
        }
        ans[a[i][2]] = j + 1;
    }
    cout <<room<<endl;
    for(int i : ans){
        cout <<i<<' ';
    }
    return 0;
}