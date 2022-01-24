#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

char c[2 * MAX + 3];

int main(){
    string s;
    cin >> s;
    const int N = s.size();
    c[0] = '@';
    c[2 * N + 2] = '!';
    c[2 * N + 1] = '#';
    for(int i = 1;i<=N;i++){
        c[2 * i - 1] = '#';
        c[2 * i] = s[(i - 1)];
    }
    int C = 0;
    int R = 0;
    int P[2 * N + 3] = {0};
    for(int i = 1;i < 2 * N + 2;i++){
        int mr = 2 * C - i;
        if(i < R){
            P[i] = min(R - i, P[mr]);
        }
        while(c[i + (P[i] + 1)] == c[i - (P[i] + 1)])   P[i]++;
        if(i + P[i] > R){
            C = i;
            R = P[i] + i;
        }
    }
    int res = 0;
    int start = -1;
    for(int i= 0;i<2 * N + 3;i++){
        if(res < P[i]){
            res = P[i];
            start = i - P[i];
        }
    }
    string ans = "";
    if(res & 1){
        res = 2 * res + 1;
        for(int i = start;i < start + res;i++){
            if(c[i] >= 'a' && c[i] <= 'z')  ans += c[i];
        }
    }
    else{
        res = 2 * res;
        for(int i = start;i < start + res;i++){
            if(c[i] >= 'a' && c[i] <= 'z')  ans += c[i];
        }
    }
    cout <<ans<<endl;
    return 0;
}