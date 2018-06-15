#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int road[n] = {};
    int from , to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        from--;
        to--;
        road[from]++;
        road[to]++;
    }

    for(int i = 0; i < n; i++){
        cout << road[i] << endl;
    }

    return 0;
}