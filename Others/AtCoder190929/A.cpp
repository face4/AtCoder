#include<iostream>
using namespace std;

pair<int,int> memo[2000001];
bool v[2000001] = {};

int main(){
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < m; i++)  cin >> b[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int w = a[i]+b[j];
            if(v[w]){
                cout << memo[w].first << " " << memo[w].second << " " << i << " " << j << endl;
                return 0;
            }
            v[w] = true;
            memo[w] = {i, j};
        }
    }
    cout << -1 << endl;
    return 0;
}