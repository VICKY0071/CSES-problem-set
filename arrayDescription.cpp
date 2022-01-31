#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int getIntersection(int l1, int r1, int l2, int r2){
    
}

int main(){
    int n, m;
    cin >> n >> m;
    int x[n];
    for(int i = 0; i< n;i++)    cin >> x[i];
    int i = 0;
    while(i < n){
        int j = i + 1;
        while(j < n && x[j] == 0 && x[i] == 0){
            j++;
        }
        int len = j - i;
        int res = 1;
        if(len == 1){
            if(i > 0 && i < n - 1){
                int l1 = max(1, x[i - 1] - 1);
                int r1 = min(m, x[i - 1] + 1);
                int l2 = max(1, x[i + 1] - 1);
                int r2 = min(m, x[i + 1] + 1);
                 res = ((res % MOD) * (getIntersection(l1, r1, l2, r2))) % MOD;
            }
            else if(i > 0){
                int l = max(1, x[i - 1] - 1);
                int r = min(m, x[i - 1] + 1);
                res = ((res % MOD) * (r - l + 1)) % MOD;
            }
            else if(j < n - 1){
                int l = max(1, x[i + 1] - 1);
                int r = min(m, x[i + 1] + 1);
                res = ((res % MOD) * (r - l + 1)) % MOD;
            }   
            else{
                res = ((res % MOD) * m) % MOD;
            }
        }
    }
    return 0;
}