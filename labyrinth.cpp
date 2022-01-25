#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> start(2), end(2);
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j] == 'A')  start = vector<int>{i, j};
            if(a[i][j] == 'B')  end = vector<int>{i, j};
        }
    }
    queue<pair<int, int>> q;
    int par[n][m][2];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            par[i][j][0] = par[i][j][1] = -1;
        }
    }
    bool found = false;
    q.push({start[0], start[1]});
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        if(temp.first == end[0] && temp.second == end[1]){
            found = true;
            break;
        }
        for(int i = 0;i<4;i++){
            int rr = temp.first + dr[i];
            int cc = temp.second + dc[i];
            if(rr < 0 || cc < 0 || rr > n - 1 ||cc > m - 1 || (rr == start[0] && cc == start[1]) || par[rr][cc][0] != -1 || a[rr][cc] == '#'){
                continue;
            }
            par[rr][cc][0] = temp.first, par[rr][cc][1] = temp.second;
            q.push({rr, cc});
        }
    }
    if(!found){
        cout <<"NO\n";
    }
    else{
        cout <<"YES\n";
        string s = "";
        while(true){
            int x = par[end[0]][end[1]][0], y = par[end[0]][end[1]][1];
            // cout <<x<<' '<<y<<endl;
            if(x == -1){
                break;
            }
            if(x + 1 == end[0]){
                s += 'D';
            }
            else if(x - 1 == end[0]){
                s += 'U';
            }
            else if(y + 1 == end[1]){
                s += 'R';
            }
            else{
                s += 'L';
            }
            end[0] = x, end[1] = y;
        }
        reverse(s.begin(), s.end());
        cout <<s.size()<<endl;
        cout <<s<<endl;
    }
    return 0;
}