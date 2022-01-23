#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    int currMax = -1;
    int ans = 0;
    for(int i =0;i<n;i++){
        int v;
        cin >> v;
        if(currMax == -1){
            currMax = v;
        }
        else{
            if(v < currMax){
                ans += (currMax - v);
            }
            else{
                currMax = v;
            }
        }
    }
    cout <<ans<<endl;
    return 0;
}