#include <bits/stdc++.h>

using namespace std;

class Trie{
    class Node{
        public:
        Node * mp[26];
        bool isEnd;
        Node(){
            for(int i = 0;i<26;i++) mp[i] = NULL;
            isEnd = false;
        }
    } * root;
    public:
    Trie(){
        this->root = new Node();
    }
    void insert(string& s){
        Node * curr = this->root;
        for(char c : s){
            if(!curr->mp[c - 'a']){
                curr->mp[c - 'a'] = new Node();
            }
            curr = curr->mp[c - 'a'];
        }
    }
    bool search(string & s){
        Node * curr = this->root;
        for(char c : s){
            if(!curr->mp[c - 'a'])  return false;
            curr = curr->mp[c - 'a'];
        }
        return curr && curr->isEnd;
    }
};

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    unordered_map<string, int> l;
    for(int i = 0;i<n;i++){
        string k;
        cin >> k;
        l[k] = 0;
    }
    

    return 0; 
}