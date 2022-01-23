#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int present[n + 1] = {0};
    for(int i = 0;i<n - 1;i++){
        int c;
        cin >> c;
        present[c] = 1;
    }
    int ans = -1;
    for(int i = 1;i <= n;i++){
        if(present[i] == 0){
            ans = i;
            break;
        }
    }
    cout <<ans<<endl;
    return 0;
}