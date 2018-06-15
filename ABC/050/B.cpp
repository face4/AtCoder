#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int T[n], sum = 0;
    for(int i = 0; i < n; i++){
        cin >> T[i];
        sum += T[i];
    }  

    int m, index, t;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> index >> t;
        cout << sum + (t-T[index-1]) << endl;
    }

    return 0;
}