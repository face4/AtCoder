#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> path(n+1);

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    set<int> way;
    for(int i = 0; i < path[1].size(); i++){
        way.insert(path[1][i]);
    }

    bool judge = false;
    for(int x : way){
        for(int i = 0; i < path[x].size(); i++){
            if(path[x][i] == n) judge = true;
        }
    }

    if(judge)   cout << "POSSIBLE" << endl;
    else        cout << "IMPOSSIBLE" << endl;

    return 0;
}