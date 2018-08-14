#include<iostream>
#include<map>
using namespace std;

int main(){
    int n, k, x;
    cin >> n >> k;

    map<int, int> rev;

    for(int i = 0; i < k; i++){
        cin >> x;
        rev[x] = i+1;
    }

    auto it = rev.end();
    it--;

    for(int i = k; i < n; i++){
        cout << (*it).second << endl;
        cin >> x;
        rev[x] = i+1;

        if(x < (*it).first) it--;
    }

    cout << (*it).second << endl;

    return 0;
}