// editorialを読んだ　天才
#include<iostream>
#include<set>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int l;
    cin >> l;
    int dep = 1;
    while(1<<(dep+1) <= l)  dep++;
    set<pii> s[dep+1];
    for(int i = 1; i <= dep; i++)   s[i].insert({i+1, 0}), s[i].insert({i+1, 1<<(i-1)});
    int num = dep*2;
    for(int i = dep; i >= 1; i--){
        // 今表現出来ていないのは S = [2^dep, l)
        // iの左側で表現出来ているのは[0, 2^(i-1))
        // iの左側で表現出来ているものに1つ加える(i->dep+1に辺を張る)事によって
        // Sの一部を覆う事が出来るなら覆う　出来ないなら何もしない
        if(l - (1<<(i-1)) >= 1<<dep){
            s[i].insert({dep+1, l - (1<<(i-1))});
            num++;
            l -= 1<<(i-1);
        }
    }
    cout << dep+1 << " " << num << endl;
    for(int i = 1; i <= dep; i++){
        for(pii p : s[i])   cout << i << " " << p.first << " " << p.second << endl;
    }
    return 0;
}