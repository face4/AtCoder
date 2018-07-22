#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int t = 0, tmpt, x = 0, tmpx, y = 0, tmpy;
    for(int i = 0; i < n; i++){
        cin >> tmpt >> tmpx >> tmpy;
        int dist = abs(tmpx-x) + abs(tmpy-y);
        if(dist > tmpt-t || dist%2 != (tmpt-t)%2){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}