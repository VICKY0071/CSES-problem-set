#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<char>>& a, int i, int j, int n, int m){
    if(i < 0 || j < 0 || i > n -1 || j > m - 1 || a[i][j] == '#')   return;
    a[i][j] = '#';
    dfs(a, i + 1, j, n, m);
    dfs(a, i, j + 1, n, m);
    dfs(a, i, j - 1, n, m);
    dfs(a, i - 1, j, n, m);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> c(n, vector<char>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)  cin >> c[i][j];
    }
    int ans = 0;
    for(int i= 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(c[i][j] == '.'){
                ans++;
                dfs(c, i, j, n, m);
            }
        }
    }
    cout <<ans<<endl;
    return 0;
}