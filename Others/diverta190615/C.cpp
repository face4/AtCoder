#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.rbegin(), v.rend());
    multiset<int> add, sub;
    if(v[0] < 0){
        add.insert(v[0]);
        for(int i = 1; i < n; i++)  sub.insert(v[i]);
    }else if(v[n-1] >= 0){
        sub.insert(v[n-1]);
        for(int i = 0; i < n-1; i++)    add.insert(v[i]);
    }else{
        int i = 0;
        while(v[i] >= 0)    add.insert(v[i++]);
        while(i < n)        sub.insert(v[i++]);
    }
    vector<int> a, b;
    int val;
    while(a.size() != n-1){
        if(sub.size() >= add.size()){
            auto ait = --add.end(), bit = sub.begin();
            int x = *ait, y = *bit;
            add.erase(ait), sub.erase(bit);
            a.push_back(x), b.push_back(y);
            add.insert(x-y);
            val = x-y;
        }else{
            auto ait = --add.end(), bit = sub.begin();
            int x = *ait, y = *bit;
            add.erase(ait), sub.erase(bit);
            a.push_back(y), b.push_back(x);
            sub.insert(y-x);
            val = y-x;
        }
    }
    
    cout << val << endl;
    for(int i = 0; i < n-1; i++)    cout << a[i] << " " << b[i] << endl;

    return 0;
}