#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int a[26] = {0};
    for(char c : s){
        a[c - 'A']++;
    }
    int odd = 0;
    for(int i = 0;i<26;i++){
        if(a[i] & 1)    odd++;
    }
    if(odd > 1){
        cout <<"NO SOLUTION\n";
        return 0;
    }
    char res[s.size()];
    int lo = 0;
    int hi = s.size() - 1;
    for(int i = 0;i<26;i++){
        while(a[i] > 1){
            char c = (i + 'A');
            res[lo++] = c;
            res[hi--] = c;
            a[i] -= 2;
        }
    }
    for(int i = 0;i<26;i++){
        if(a[i] == 1){
            res[(s.size() >> 1)] = (i + 'A');
        }
   }
   for(int i = 0;i<s.size();i++)    cout <<res[i];
   cout <<endl;
   return 0;
}