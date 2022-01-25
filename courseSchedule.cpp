#include <bits/stdc++.h>

using namespace std;

int cycle_start = -1;
int cycle_end;
int colors[100001];
stack<int> st;
bool dfs(vector<vector<int>>& a, int i){
    colors[i] = 1;
    for(auto e : a[i]){
        if(colors[e] == 0){
            if(dfs(a, e))    return true;
        }
        else if(colors[e] == 1){
            cycle_start = i;
            cycle_end = e;
            return true; 
        }
    }
    st.push(i);
    colors[i] = 2;
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    for(int i = 0;i<m;i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    for(int i = 1;i<n + 1;i++){
        if(colors[i] == 0 && dfs(a, i)) break;
    }

    if(cycle_start != -1){
        cout <<"IMPOSSIBLE\n";
    }
    else{
        while(!st.empty()){
            cout<<st.top()<<' ';
            st.pop();
        }
    }
    cout <<endl;
    return 0;
}