#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    bool one[n+1], enu[n+1];
    for(int i = 0; i < n+1; i++)    one[i] = enu[i] = false;

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(a == 1)  one[b] = true;
        if(b == n)  enu[a] = true;
    }

    bool judge = false;
    for(int i = 2; i <= n-1; i++){
        if(one[i] && enu[i])    judge = true;
    }

    if(judge)   cout << "POSSIBLE" << endl;
    else        cout << "IMPOSSIBLE" << endl;

    return 0;
}