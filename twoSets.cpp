#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if(sum & 1){
        cout<<"NO\n";
        return 0;
    }
    vector<int> res, res2;
    int hlf = (sum >> 1);
    for(;n >= 1;n--){
        if(hlf > 0 && n <= hlf){
            res.push_back(n);
            hlf -= n;
        }
        else{
            res2.push_back(n);
        }
    }
    if(hlf == 0){
        cout <<"YES\n";
        cout <<res.size()<<endl;
        for(int i : res)    cout <<i<<' ';
        cout <<endl;
        cout <<res2.size()<<endl;
        for(int i : res2)   cout <<i<<' ';
        cout <<endl;
    }
    else    cout <<"NO\n";
    return 0;

}