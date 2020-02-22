#include<iostream>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        if(s.count(x)){
            cout << "NO" << endl;
            return 0;
        }
        s.insert(x);
    }
    cout << "YES" << endl;
    return 0;
}
