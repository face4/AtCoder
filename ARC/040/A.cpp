#include<iostream>
#include<algorithm>
using namespace std;

#define printb(x, a, b) if(x) cout << a << endl; else cout << b << endl

int main(){
    int n;
    cin >> n;

    int b = 0, r = 0;
    string line;

    for(int i = 0; i < n; i++){
        cin >> line;
        b += count(line.begin(), line.end(), 'B');
        r += count(line.begin(), line.end(), 'R');
    }

    if(b == r)  cout << "DRAW" << endl;
    else        printb(b > r, "AOKI", "TAKAHASHI");

    return 0;
}