#include <bits/stdc++.h>
#define int long long 

using namespace std;

int32_t main(){
    int n;
    cin >> n;
    while(n > 1){
        cout <<n<<' ';
        if(n & 1){
            n = (n * 3) + 1;
        }
        else{
            n >>= 1;
        }
    }
    cout <<1<<endl;
    return 0;
}