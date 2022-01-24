#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i<n;i++)  cin >> a[i];
    set<int> res;
    int cumSum[n];
    cumSum[0] = a[0];
    for(int i=  1;i<n;i++)  cumSum[i] =cumSum[i - 1] + a[i];
    for(int len = 1;len <= n;len++){
        for(int i = 0;i <= n - len;i++){
            int j = i + len - 1;
            res.insert(cumSum[j] - (i > 0 ? cumSum[i - 1] : 0));
        }
    }
    cout <<res.size()<<endl;
    for(int i : res)    cout <<i<<" ";
    return 0;
}