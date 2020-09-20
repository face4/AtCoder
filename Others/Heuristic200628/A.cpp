// 工夫0の山登り
#include<iostream>
#include<set>
#include<random>
#include<chrono>
using namespace std;
typedef long long ll;

int main(){
    auto start = std::chrono::system_clock::now(); 
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<int> randd(1,365);
    uniform_int_distribution<int> randq(1,26);
    
    int d;
    cin >> d;
    int c[27];
    for(int i = 1; i <= 26; i++) cin >> c[i];
    int s[365+1][27];
    for(int i = 1; i <= d; i++){
        for(int j = 1; j <= 26; j++){
            cin >> s[i][j];
        }
    }
    set<int> h[27];
    for(int i = 1; i <= 26; i++) h[i].insert(0), h[i].insert(d+1);
    int t[365+1];
    int last[27] = {};
    ll now = 0;
    for(int i = 1; i <= 365; i++){
        t[i] = i%26+1;
        h[t[i]].insert(i);
        now += s[i][t[i]];
        last[t[i]] = i;
        ll dec = 0;
        for(int j = 1; j <= 26; j++)    dec += c[j]*(i-last[j]);
        now -= dec;
    }

    while(1){
        auto nowt = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start).count();
        if(nowt > 1900)  break;
        int d = randd(mt), q = randq(mt);
        ll diff = 0;
        int bef = t[d];
        diff -= s[d][bef];
        h[bef].erase(d);
        {
            int from = *(--h[bef].lower_bound(d));
            int to = *(h[bef].lower_bound(d));
            diff -= (ll)c[bef]*(to-d)*(d-from);
        }
        t[d] = q;
        diff += s[d][q];
        h[q].insert(d);
        {
            int from = *(--h[q].lower_bound(d));
            int to = *(h[q].upper_bound(d));
            diff += (ll)c[q]*(to-d)*(d-from);
        }
        if(diff < 0){
            h[t[d]].erase(d);
            t[d] = bef;
            h[t[d]].insert(d);
        }else{
            now += diff;
        }
    }

    for(int i = 1; i <= d; i++) cout << t[i] << endl;
    
    return 0;
}