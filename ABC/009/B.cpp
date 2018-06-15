#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> price;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        price.insert(x);
    }

    auto it = price.end();
    it--;
    it--;
    cout << *it << endl;
    return 0;
}