#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

struct data{
    int i, j, pos;
    bool operator<(const data other) const{
        if(i != other.i)    return i < other.i;
        else                return j < other.j;
    }
};

int main(){
    int n;
    cin >> n;

    vector<data> taka, aoki;
    int a, b;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        taka.push_back(data{a+b, a, i});
        aoki.push_back(data{b+a, b, i});
    }
    
    sort(taka.rbegin(), taka.rend());
    sort(aoki.rbegin(), aoki.rend());

    // for(data d : taka)  cout << d.i << " " << d.j << endl;
    // for(data d : aoki)  cout << d.i << " " << d.j << endl;

    bool used[n];
    memset(used, 0, sizeof(used));

    ll ta = 0, ao = 0;
    int curt = 0, cura = 0;

    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            while(used[taka[curt].pos]) curt++;
            used[taka[curt].pos] = true;
            ta += taka[curt].j;
            curt++;
        }else{
            while(used[aoki[cura].pos]) cura++;
            used[aoki[cura].pos] = true;
            ao += aoki[cura].j;
            cura++;
        }
    }

    cout << ta-ao << endl;

    return 0;
}