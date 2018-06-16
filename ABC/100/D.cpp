#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;

    ll cake[n][3];
    for(int i = 0; i < n; i++){
        cin >> cake[i][0] >> cake[i][1] >> cake[i][2];
    }

    ll ans = LLONG_MIN;

    for(int i = 0; i < 8; i++){
        ll score[n] = {};
        for(int j = 0; j < n; j++){
            if(i & 1 == 1)      score[j] += cake[j][0];
            else                score[j] -= cake[j][0];
            if(i/2 & 1 == 1)    score[j] += cake[j][1];
            else                score[j] -= cake[j][1];
            if(i/4 & 1 == 1)    score[j] += cake[j][2];
            else                score[j] -= cake[j][2];
        }

        sort(score, score+n);
        reverse(score, score+n);

        ll can = 0;
        for(int i = 0; i < m; i++)  can += score[i];

        ans = max(can, ans);
    }

    cout << abs(ans) << endl;

    return 0;
}