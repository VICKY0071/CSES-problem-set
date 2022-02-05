#include <bits/stdc++.h>
using namespace std;

// in this question I understood that using a map at times 
// is faster tha using the unordered map as this was TLE in unordered_map 
// and got accepted in map.

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int res = 0;
    map<int, int> k;
    int distinct = 0;
    int j = 0;
    for(int i = 0;i < n;i++){
        if(k.count(a[i]) == 0 || k[a[i]] == 0){
            distinct++;
        }
        k[a[i]]++;
        while(j < i && distinct < (i - j + 1)){
            k[a[j]]--;
            if(k[a[j]] == 0){
                distinct--;
            }
            j++;
        }
        res= max(res, i - j + 1);
    }
    cout <<res<<endl;
    return 0;
}