#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int rowc[100000] = {}, colc[100000] = {}, cnt[100001] = {};
vector<int> rowv[100000];

int main(){
    int r, c, k, n, x, y;
    cin >> r >> c >> k >> n;

    while(n-- > 0){
        cin >> x >> y;
        --x, --y;
        rowv[x].push_back(y);
        rowc[x]++;
        colc[y]++;
    }

    for(int i = 0; i < c; i++)  cnt[colc[i]]++;

    ll ans = 0;
    for(int i = 0; i < r; i++){
        if(rowc[i] > k)  continue;
        int toadd = cnt[k-rowc[i]];
        for(int j : rowv[i]){
            if(colc[j] == k-rowc[i]+1)    toadd++;
            else if(colc[j] == k-rowc[i]) toadd--;
        }
        ans += toadd;
    }

    cout << ans << endl;

    return 0;
}
