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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({a[0][1], 1});
    int id = 1;
    for(int i = 1;i<n;i++){
        int j = 0;
        for(;j < rooms.size() && rooms[j] >= a[i][0];j++);
        if(!q.empty() && q.top().first < a[i][0]){
            int rm = q.top().second;
            q.pop();
            ans[a[i][2]] = rm;
            q.push({a[i][1], rm});
        }   
        else{
            room++;
            q.push({a[i][1], ++id});
            ans[a[i][2]] = id;
        }
    }
    cout <<room<<endl;
    for(int i : ans){
        cout <<i<<' ';
    }
    return 0;
}