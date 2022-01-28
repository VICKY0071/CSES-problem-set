#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int ss = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        ss += a[i];
    }
    int dp[100001] = {0};
    dp[0] = 1;
    for(int i = 0;i < n;i++){
        for(int j = ss;j - a[i] >= 0;j--){
            if(dp[j - a[i]] == 1){
                dp[j] = 1;
            }
        }
    }
    vector<int> res;
    for(int i= 1;i <= ss;i++){
        if(dp[i] == 1){
            res.push_back(i);
        }
    }
    cout <<res.size()<<endl;
    for(int i : res)    cout <<i<<' ';
    return 0;

}