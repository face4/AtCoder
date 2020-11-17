#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    for(int i = 0; i <= 200001; i++)    s.insert(i);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        s.erase(x);
        cout << *s.begin() << endl;
    }
    return 0;
}