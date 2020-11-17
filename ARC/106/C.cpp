#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    if(m == 0){
        for(int i = 0; i < n; i++){
            cout << 2*i+1 << " " << 2*i+2 << endl;
        }
        return 0;
    }
    if(m < 0 || m >= n-1){
        cout << -1 << endl;
        return 0;
    }
    int now = 2;
    for(int i = 0; i < m+1; i++){
        cout << now << " " << now+1 << endl;
        now += 2;
    }
    cout << 1 << " " << now++ << endl;
    for(int i = 0; i < n-(m+1)-1; i++){
        cout << now << " " << now+1 << endl;
        now += 2;
    }
    return 0;
}