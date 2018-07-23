#include<iostream>
#include<stack>
using namespace std;

bool path[51][51] = {};
int n, m, a, b;

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        path[a][b] = path[b][a] = true;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!path[i][j]) continue;

            path[i][j] = path[j][i] = false;

            stack<int> s;
            s.push(a);
            bool visit[n+1];
            for(int i = 0; i < n+1; i++)    visit[i] = false;

            while(!s.empty()){
                int x = s.top(); s.pop();
                if(visit[x])    continue;

                visit[x] = true;
                for(int y = 0; y <= n; y++){
                    if(path[x][y] && !visit[y]) s.push(y);
                }
            }

            bool judge = true;
            for(int i = 1; i <= n; i++) judge &= visit[i];
            if(!judge)   cnt++;
            path[i][j] = path[j][i] = true;
        }
    }

    cout << cnt/2 << endl;

    return 0;
}