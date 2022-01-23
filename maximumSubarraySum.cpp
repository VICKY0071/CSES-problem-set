#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];
    int posSum = 0;
    int negSum = INT_MIN;
    int res = 0;
    for(int i= 0;i<n;i++){
        posSum = max(0LL, posSum + a[i]);
        res = max(posSum, res);
        negSum = max(negSum, a[i]);
    }
    if(res <= 0)    cout <<negSum<<endl;
    else    cout <<res<<endl;
    return 0;
}