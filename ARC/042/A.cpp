#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool appear[100001] = {};

int main(){
    int n, m, a;
    cin >> n >> m;

    vector<int> write(m);
    for(int i = 0; i < m; i++)  cin >> write[i];

    reverse(write.begin(), write.end());

    for(int i = 0; i < m; i++){
        if(!appear[write[i]]){
            cout << write[i] << endl;
            appear[write[i]] = true;
        }
    }

    for(int i = 1; i <= n; i++){
        if(!appear[i])  cout << i << endl;
    }

    return 0;
}