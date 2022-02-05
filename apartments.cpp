#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> app(n), flats(m);
    for(int i = 0;i < n;i++)   cin >> app[i];
    for(int i = 0;i < m;i++){
        cin >> flats[i];
    }
    sort(app.begin(), app.end());
    sort(flats.begin(), flats.end());
    int i = 0;
    int cnt = 0;
    int j = 0;
    while(i < n && j < m){
        if(app[i] - k <= flats[j] && app[i] + k >= flats[j]){
            i++;
            cnt++;
            j++;
        }
        else if(app[i] - k > flats[j] ){
            j++;
        }
        else{
            i++;
        }

    }
    cout <<cnt<<endl;
    return 0;
}