#include <bits/stdc++.h>
#define int long long

using namespace std;


int32_t main(){
    int n;
    cin >> n;
    int res = 1;
    for(int i = 0; i< n;i++){
        int x;
        cin >> x;
        res = 1;
        for(int j = 2; (j * j) <= x;j++){
            int p = 0;
            while(x % j == 0){
                p++;
                x /= j;
            }
            if(p > 0)   res = res * (p + 1);
        }
        if(x != 1){
            res = res * 2;
        }
        cout <<res<<" ";
    }
    return 0;
}