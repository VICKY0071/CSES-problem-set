#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<pair<int, char>> a;
    for(int i = 0;i<n;i++){
        int x, d;
        cin >> x >> d;
        a.push_back({x, 'A'});
        a.push_back({d, 'D'});
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    int bestAns = 0;
    a.push_back({-1, 'D'});
    for(int i = 0;i<2 * n;i++){
        if(i == 0){
            cnt = (a[i].second == 'A');
        }
        else{
            if(a[i].second == 'A'){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        bestAns = max(bestAns, cnt);
    }
    cout <<bestAns<<endl;
}