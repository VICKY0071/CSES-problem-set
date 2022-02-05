#include <bits/stdc++.h>

using namespace std;

static bool compare(vector<int>& a, vector<int>& b){
    return a[0] != b[0] ? a[0] < b[0] : (a[1] > b[1]);
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i = 0;i < n;i++){
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    vector<int> itContains(n, 0), containsIt(n, 0);
    sort(a.begin(), a.end(), compare);
    int mxRB = -1;
    for(int i = 0;i < n;i++){
        if(mxRB != -1 && a[i][1] <= a[mxRB][1]){
            itContains[a[mxRB][2]]++;
            containsIt[a[i][2]]++;
        }
        if(mxRB == -1 || a[mxRB][1] < a[i][1]){
            mxRB = i;
        }
    }
    for(int i : itContains) cout<<i<<' ';
    cout <<endl;
    for(int i : containsIt) cout <<i<<' ';
    return 0;
}