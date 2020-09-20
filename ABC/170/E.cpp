#include<iostream>
#include<vector>
#include<set>
using namespace std;

multiset<int> kind[200001];

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> rate(n+1), now(n+1);
    for(int i = 1; i <= n; i++){
        cin >> rate[i] >> now[i];
        kind[now[i]].insert(rate[i]);
    }
    multiset<int> eq;
    for(int i = 1; i <= 200000; i++){
        if(kind[i].empty()) continue;
        eq.insert(*(kind[i].rbegin()));
    }
    while(q--){
        int c, d;
        cin >> c >> d;
        int x = *(kind[now[c]].rbegin());
        kind[now[c]].erase(kind[now[c]].find(rate[c]));
        if(x == rate[c]){
            eq.erase(eq.find(x));
            if(!kind[now[c]].empty()) eq.insert(*(kind[now[c]].rbegin()));
        }
        now[c] = d;
        x = kind[now[c]].empty() ? 0 : *(kind[now[c]].rbegin());
        if(rate[c] > x){
            if(x>0) eq.erase(eq.find(x));
            eq.insert(rate[c]);
        }
        kind[now[c]].insert(rate[c]);
        cout << *eq.begin() << endl;
    }
    return 0;
}