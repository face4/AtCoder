#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> dia;
    int n, d;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> d;
        dia.insert(d);
    }

    cout << dia.size() << endl;
    return 0;
}