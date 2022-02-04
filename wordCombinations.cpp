#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

// learnt a new way of implemnting the trie usign trie array

int trie[1000005][26];
int endpoint[1000005];
int dp[5001];
int id = 0;

void insert(string& s){
    int curr = 0;
    for(char c : s){
        if(trie[curr][c - 'a'] == 0)    trie[curr][c - 'a'] = ++id;
        curr = trie[curr][c - 'a'];
    }
    endpoint[curr] = 1;
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    for(int i = 0;i < k;i++){
        string l;
        cin >> l;
        insert(l);
    }
    const int n = s.size();
    dp[n] = 1;
    for(int i = n - 1;i >= 0;i--){
        int curr = 0;
        for(int j = i;j < n;j++){
            if(trie[curr][s[j] - 'a'] == 0) break;
            curr = trie[curr][s[j] - 'a'];
            if(endpoint[curr] == 1) dp[i] = (dp[i] + dp[j + 1]) % mod; 
        }
    }
    cout <<dp[0]<<endl;
    return 0;
}