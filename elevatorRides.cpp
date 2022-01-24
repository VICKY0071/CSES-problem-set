#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i<n;i++)  cin >> a[i];
    sort(a.begin(), a.end());
    int v = -1;
    int x;
    int cnt=  0;
    if(n == 1){  
        cout <<1<<endl;
        return 0;
    }
    while(!a.empty()){
        // cout <<v<<endl;
        if(v == -1){
            v = a.back();
        }
        x = k - v;
        auto ptr = lower_bound(a.begin(), a.end(), x);
        if(ptr == a.end()){
            ptr--;
            ptr--;
        }
        if(*ptr == x){
            a.erase(ptr);
            a.pop_back();
            v = -1;
            cnt++;
        }
        else{
            if(ptr == a.begin()){
                a.pop_back();
                v = -1;
                cnt++;
            }
            else{
                ptr--;
                v += *ptr;
                a.erase(ptr);
            }
        }
        // for(int i : a)   cout <<i<<' ';
        // cout <<endl;
    }
    cout <<cnt<<endl;
    return 0;
}