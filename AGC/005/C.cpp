#include<iostream>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    multiset<int> s;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        s.insert(x);
    }
    int diam = *s.rbegin();
    bool even = diam%2==0;
    int to = diam/2+1;
    while(diam >= to){
        bool valid = s.size() >= 2;
        for(int i = 0; i < 2; i++){
            if(valid && s.count(diam))      s.erase(s.find(diam));
            else                            valid = false;
        }
        if(!valid){
            cout << "Impossible" << endl;
            return 0;
        }
        diam--;
    }
    if(even){
        if(s.size() == 0 || s.count(to-1) == 0){
            cout << "Impossible" << endl;
            return 0;
        }else{
            s.erase(s.find(to-1));
        }
    }else{
        to++;
    }
    cout << (s.size() == 0 || *s.begin() >= to ? "Possible" : "Impossible") << endl;
    return 0;
}