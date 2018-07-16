#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct data{
    int a, b;
    data(int _a, int _b) : a(_a), b(_b) {}
    bool operator<(const data other) const{
        return a < other.a;
    }
};

int main(){
    long long n, k;
    cin >> n >> k;

    int a, b;

    vector<data> v;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back(data(a,b));
    }

    sort(v.begin(), v.end());

    long long accum = 0;
    for(data x : v){
        accum += x.b;
        if(accum >= k){
            cout << x.a << endl;
            return 0;
        }
    }

}