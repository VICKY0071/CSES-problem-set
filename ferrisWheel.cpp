#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, cap;
    cin >> n >> cap;
    int a[n];
    for(int i = 0;i < n;i++)   cin >> a[i];
    int lo = 0;
    int hi = n - 1;
    int ans = 0;
    sort(a, a + n);
    while(lo <= hi){
        if(lo == hi){
            ans++;
            break;
        }
        int sum = a[lo] + a[hi];
        if(sum <= cap){
            lo++;
            hi--;
        }
        else if(sum > cap){
            hi--;
        }
        ans++;
    }
    cout <<ans<<endl;
    return 0;
}