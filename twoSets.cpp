#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if(sum & 1){
        cout<<"NO\n";
        return 0;
    }

    return 0;

}