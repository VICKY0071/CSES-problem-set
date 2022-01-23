#include <bits/stdc++.h>

using namespace std;

void op(string s[], int row, int col){
    for(int i = col;i<8;i++){
        s[row][i] = '*';
    }
    for(int i = row;i < 8;i++){
        s[i][col] = '*';
    }
    for(int r = row, c = col;r < 8 && c < 8;r++, c++){
        s[row][col] = '*';
    }
    
    for(;row < 8 && col >= 0;row++, col--){
        s[row][col] = '*';
    }
}

int res = 0;
void solve(string s[], int row, int col, int cnt = 0){
    if(row == 8){
        if(cnt == 8){
            res++;
        }
        return;
    }
    else{
        for(int i = 0;i<8;i++){
            if(s[row][i] != '*'){
                s[row][i] = '*';
                string x[8];
                for(int l = 0;l < 8;l++)    x[l] = s[l];
                op(s, row, i);
                solve(s, row + 1, cnt + 1);
                for(int l = 0;l < 8;l++)    s[l] = x[l];
            }
        }
    }
}

int main(){ 
    string s[8];
    for(int i = 0;i<8;i++){
        cin >> s[i];
    }
    solve(s, 0, 0);
    cout <<res<<endl;
    return 0;
}