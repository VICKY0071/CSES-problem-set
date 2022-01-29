#include <bits/stdc++.h>

using namespace std;

class Project{
    public:
    int s, e, p;
    Project(){}
    Project(int s, int e, int p){
        this->s = s;
        this->e = e;
        this->p = p;
    }
};

int main(){
    int n;
    cin >> n;
    vector<Project> a(n);
    for(int i= 0;i < n;i++){
        int s, e, p;
        cin >> s >> e >> p;
        a[i] = Project(s, e, p);
    }
    return 0;
}