#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int bestAns = 0;
    int currCnt = 0;
    const int n = s.size();
    for(int i = 0;i<n;i++){
        if(i == 0){
            currCnt = 1;
        }
        else{
            if(s[i] == s[i - 1]){
                currCnt++;
            }
            else{
                bestAns = max(currCnt, bestAns);
                currCnt = 1;
            }
        }
        bestAns = max(bestAns, currCnt);
    }
    cout <<bestAns<<endl;
    return 0;
}