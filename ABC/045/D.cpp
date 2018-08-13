#include<iostream>
#include<map>
#include<numeric>
using namespace std;

#define inRange(x, a, b) a <= x && x < b
typedef long long ll;

int dx[9] = {-1,-1,-1,0,0,1,1,1};
int dy[9] = {1,0,-1,1,-1,1,0,-1};

int main(){
    int h, w, n, a, b;

    cin >> h >> w >> n;

    map<pair<int,int>, int> m;
    
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        a--;
        b--;
        for(int j = 0; j < 9; j++){
            int na = a + dx[j];
            int nb = b + dy[j];
            if(inRange(na, 1, h-1) && inRange(nb, 1, w-1)){
                m[{na,nb}]++;
            }
        }
    }

    ll cnt[10] = {};
    for(auto x : m){
        cnt[x.second]++;
    }

    cnt[0] = ll(h-2) * (w-2) - accumulate(cnt, cnt+10, 0ll);

    for(ll x : cnt)    cout << x << endl;
    
    return 0;
}