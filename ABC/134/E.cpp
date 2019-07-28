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
    multiset<int> s;
    for(int i = 0; i < n; i++){
        if(s.empty()){
            s.insert(v[i]);
        }else{
            auto it = s.lower_bound(v[i]);
            if(it == s.begin()){
                s.insert(v[i]);
            }else{
                it--;
                s.erase(it);
                s.insert(v[i]);
            }
        }
    }
    cout << s.size() << endl;
    return 0;
}