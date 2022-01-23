#include <bits/stdc++.h>
#define int long long 

using namespace std;

int32_t main(){
    int n;
    cin >> n;
    if(n == 1){
        cout <<1<<endl;
        return 0;
    }
    if(n <= 3){
        cout <<"NO SOLUTION\n";
        return 0;
    }
    if((n & 1) == 0){
        cout <<(n >> 1) + 1<<' ';
        int lo = 1, hi = n;
        while(lo < hi - 1){
            cout <<lo++<<' '<<hi--<<' ';
        }
        cout <<(n >> 1)<<' ';
    }
    else{
        cout <<(n >> 1) + 1<<' ';
        int lo = 1, hi = n;
        while(lo < hi){
            cout <<lo++<<' '<<hi--<<' ';
        }
    }
    cout <<endl;
    return 0;
}