#include<iostream>
#include<set>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    bool fri[n+1][n+1];

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            fri[i][j] = false;
        }
    }

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        fri[a][b] = fri[b][a] = true;
    }

    for(int i = 1; i <= n; i++){
        set<int> first;
        for(int j = 1; j <= n; j++){
            if(fri[i][j])   first.insert(j);
        }

        set<int> second;
        for(int x : first){
            for(int j = 1; j <= n; j++){
                if(fri[x][j])   second.insert(j);
            }
        }

        first.insert(i);

        for(int x : first){
            auto it = second.find(x);
            if(it != second.end())  second.erase(it);
        }

        cout << second.size() << endl;
    }
    return 0;
}