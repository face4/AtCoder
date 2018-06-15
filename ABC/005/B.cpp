#include<iostream>
using namespace std;

int main(){
    int n, t, fastest = 101;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        fastest = min(t,fastest);
    }
    cout << fastest << endl;
    return 0;
}