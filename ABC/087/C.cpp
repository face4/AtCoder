#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int candy[2][n];
    cin >> candy[0][0];
    for(int i = 1; i < n; i++){
        cin >> candy[0][i];
        candy[0][i] += candy[0][i-1];
    }

    cin >> candy[1][0];
    candy[1][0] += candy[0][0];
    for(int i = 1; i < n; i++){
        cin >> candy[1][i];
        candy[1][i] += max(candy[1][i-1], candy[0][i]);
    }

    cout << candy[1][n-1] << endl;
    
    return 0;
}