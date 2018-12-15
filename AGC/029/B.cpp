#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    map<int, int> v[50];
    ll a;

    for(int i = 0; i < n; i++){
        cin >> a;
        int lsb = 0;
        while((1<<lsb) & ~a)    lsb++;
        lsb++;
        a /= (1ll<<lsb);
        int cp = (int)a;
        v[lsb][cp]++;
    }

    int ans = 0;
    for(int i = 0; i < 50; i++){
        if(v[i].size() == 0)    continue;
        for(auto it = v[i].rbegin(); it != v[i].rend(); it++){
            if((*it).second == 0 || (*it).first == 0)   continue; // needless?
            int tmp = (*it).first;
            int want = 0, cur = 0;
            while(tmp > 0){
                if((tmp&1) == 0)    want += 1<<cur;
                cur++;
                tmp >>= 1;
            }
            tmp = (*it).first;
            if(v[i].count(want) == 0)   continue;
            int make = min((*it).second, v[i][want]);
            (*it).second -= make, v[i][want] -= make;
            ans += make;
        }
        if(v[i].count(0))   ans += v[i][0]/2;
    }

    cout << ans << endl;

    return 0;
}