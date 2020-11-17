#include<iostream>
#include<set>
using namespace std;

typedef pair<int,int> pii;

int main(){
    int h, w;
    cin >> h >> w;
    set<pii> s;
    multiset<int> d;    // {to, from}
    for(int i = 1; i <= w; i++){
        s.insert({i, i});
        d.insert(0);
    }
    for(int i = 0; i < h; i++){
        int a, b;
        cin >> a >> b;
        auto it = s.upper_bound({a-1, 1<<30});
        int from = 0;
        while(it != s.end() && it->first <= b){
            from = max(from, it->second);
            d.erase(d.find(it->first-it->second));
            it = s.erase(it);
        }
        if(from){
            if(b == w)  b = 1<<30;
            b++;
            pii p = {b, from};
            s.insert(p);
            d.insert(b-from);
        }
        if(*d.begin() > 1e8)    cout << -1 << endl;
        else                    cout << i+1+*d.begin() << endl;
    }
    return 0;
}