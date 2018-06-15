#include<iostream>
#include<vector>
using namespace std;

int main(){
/*
    int n;
    cin >> n;
    cout << n << endl;
    for(int i = 0; i < n; i++)  cout << 1 << endl;
*/
    int n; 
    cin >> n;
    vector<int> v;
    
    int base = 1;
    while(n > 0){
        if(n&1) v.push_back(base);
        base *= 2;
        n = n>>1;
    }

    cout << v.size() << endl;
    for(int x : v)  cout << x << endl;

    return 0;
}