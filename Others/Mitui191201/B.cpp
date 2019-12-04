#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        if((int)((double)i * 1.08) == n){
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}