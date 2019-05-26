#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<char> t(q), d(q);
    for(int i = 0; i < q; i++)  cin >> t[i] >> d[i];
    int l = -1, r = n;
    while(r-l > 1){
        int mid = (l+r)/2;
        int cp = mid;
        bool ok = false;
        for(int i = 0; i < q; i++){
            if(t[i] == s[cp]){
                if(d[i] == 'L') cp--;
                else            cp++;
                if(cp < 0){
                    ok = true;
                    break;
                }
                if(cp >= n){
                    break;
                }
            }
        }
        if(ok)  l = mid;
        else    r = mid;
    }
    int ll = l;    
    l = -1, r = n;
    while(r-l > 1){
        int mid = (l+r)/2;
        int cp = mid;
        bool ok = false;
        for(int i = 0; i < q; i++){
            if(t[i] == s[cp]){
                if(d[i] == 'L') cp--;
                else            cp++;
                if(cp < 0){
                    break;
                }
                if(cp >= n){
                    ok = true;
                    break;
                }
            }
        }
        if(ok)  r = mid;
        else    l = mid;
    }
    int rr = r;
    vector<bool> v(n);
    for(int i = 0; i <= ll; i++)    v[i] = true;
    for(int i = n-1; i >= rr; i--)  v[i] = true;
    int ans = n;
    for(int i = 0; i < n; i++)  if(v[i])    ans--;
    cout << ans << endl;
    return 0;
}