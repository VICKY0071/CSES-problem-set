#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i= 0 ;i<n;i++)  cin >> a[i];
    int distinct = 0;
    unordered_map<int, int> cnt;
    int j = 0;
    int res = 0;
    for(int i = 0;i<n;i++){
        if(cnt.count(a[i]) == 0){
            distinct++;
        }
        cnt[a[i]]++;
        while(j < i && distinct > k){
            cnt[a[j]]--;
            if(cnt[a[j]] == 0)  cnt.erase(a[j]), distinct--;
            j++;
        }
        res = res + (i - j + 1);
    }
    cout <<res<<endl;
    return 0;
}