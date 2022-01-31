#include <bits/stdc++.h>

using namespace std;


priority_queue<pair<int, int>> maxQ;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minQ;

void refactor(int i, int k){
    while(abs(minQ.size() - maxQ.size()) > 1){
        if(minQ.size() > maxQ.size()){
            maxQ.push(minQ.top());
            minQ.pop();
        }
        if(maxQ.size() > minQ.size()){
            minQ.push(maxQ.top());
            maxQ.pop();
        }
    }
    while(minQ.size() > 0 && minQ.top().second < (i - k)){
        minQ.pop();
    }
    while(maxQ.size() > 0 && maxQ.top().second < (i - k)){
        maxQ.pop();
    }
}

void insert(int v, int i, int k){
    if(maxQ.empty()){
        maxQ.push({v, i});
    }
    else if(maxQ.top().first >= v){
        maxQ.push({v, i});
    }
    else{
        minQ.push({v, i});
    }

}

int getMedian(int i, int k){

}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];
    for(int i = 0;i < m;i++){
        insert(a[i], i, m);
    } 

    return 0;
}