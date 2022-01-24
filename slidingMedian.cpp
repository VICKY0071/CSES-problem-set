#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>> mx;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn;

int answer(int idx, int k){
    while(!mx.empty() && mx.top().second <= (idx - k)){
        mx.pop();
    }
    while(!mn.empty() && mn.top().second <= (idx - k)){
        mn.pop();
    }
    return mx.size() == mn.size() ? mx.top().first : (mx.size() > mn.size() ? mx.top().first : mn.top().first);
}

void insert(int v, int idx, int k){
    while(!mx.empty() && mx.top().second <= (idx - k)){
        mx.pop();
    }
    while(!mn.empty() && mn.top().second <= (idx - k)){
        mn.pop();
    }
    if(v <= mx.top().first){
        mx.push({v, idx});
    }
    else    mn.push({v, idx});
    while(mx.size() - mn.size() > 1){
        mn.push(mx.top());
        mx.pop();
    }
    while(mn.size() - mx.size() > 1){
        mn.push(mx.top());
        mx.pop();
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> res;
    for(int i = 0;i<n;i++){
        int v;
        cin >> v;
        insert(v, i, k);
        if(i >= 2){
            res.push_back(answer(i, k));
        }
        for(int i : res)    cout <<i<<" ";
    }
    return 0;
}