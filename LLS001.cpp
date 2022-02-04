#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, k;
    int x[1001] = {0};
    cin >> n >> k;
    int mx = -1;
    for(int i = 0;i < n;i++){
        int v;
        cin >> v;
        x[v]++;
        mx = max(mx, v);
    }
    int i = 1;
    for(i = 1;k > 0;i++){
        if(x[i] == 0){
            k--;
        }
    }
    cout <<--i<<endl;
}