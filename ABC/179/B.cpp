#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    while(n--){
        int x, y;
        cin >> x >> y;
        if(x == y)  count++;
        else        count = 0;
        if(count >= 3){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}