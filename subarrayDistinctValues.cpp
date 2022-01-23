#include <bits/stdc++.h>
#define int long long

using namespace std;

int e[10000000], o[10000000];

int cnt(int x, bool add, int get = false){
    if((x & 1)){
        if(get) return o[x >> 1];
        if(add) o[x >> 1]++;
        else    o[x >> 1]--;
    }
    else{
        if(get) return e[x >> 1];
        if(add) e[x >> 1]++;
        else    e[x >> 1]--;
    }
    return 1;
}

int32_t main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i= 0 ;i<n;i++)  cin >> a[i];
    int distinct = 0;
    int j = 0;
    int res = 0;
    for(int i = 0;i<n;i++){
        if(cnt(a[i], false, true) == 0){
            distinct++;
        }
        cnt(a[i], true, false);
        while(j < i && distinct > k){
            cnt(a[j], false, false);
            if(cnt(a[j], false, true) == 0) distinct--;
            j++;
        }
        res = res + (i - j + 1);
    }
    cout <<res<<endl;
    return 0;
}