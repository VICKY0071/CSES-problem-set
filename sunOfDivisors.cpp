#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> primes;

void sieve(int n){
    bool isPrime[n + 1];
    fill(isPrime, isPrime + n, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i <= n;i++){
        if(isPrime[i])  primes.push_back(i);
        if(isPrime[i] && (i * i) <= n){
            for(int j = i * i;j <= n;j += i){
                isPrime[j] = false;
            }
        }
    }
}

int32_t main(){
    int n;
    cin >> n;
    sieve(10000);
    for(int i =0 ;i < n;i++){
        int x;
        cin >> x;
        int res = 1;
        int idx = 0;
        while(x > 1){
            int cnt = 0;
            while(x % primes[idx] == 0){
                cnt++;
                x /= primes[idx];
            }
            res = res * (cnt + 1);
            idx++;
        }
        cout <<res<<endl;
    }
    return 0;
}
