#include<iostream>
#include<set>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    set<int> s;

    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        while(x%2 == 0) x /= 2;
        s.insert(x);
    }

    cout << s.size() << endl;

    return 0;
}