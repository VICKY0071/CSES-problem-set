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
    int lo = 0;
    int hi = n - 1;
    while(lo < hi){
        int sum = a[lo][0] + a[hi][0];
        if(sum == t){
            break;
        }
        if(sum > t) hi--;
        else    lo++;
    }
    if(lo >= hi){
        cout <<"IMPOSSIBLE\n";
    }
    else{
        cout <<a[lo][1] + 1<<' '<<a[hi][1] + 1<<endl;
    }
    return 0;
}