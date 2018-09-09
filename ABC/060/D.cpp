#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int N, W, w, v;
    cin >> N >> W >> w >> v;

    vector<vector<int>> value(4);
    value[0].push_back(v);

    int base = w;
    for(int i = 1; i < N; i++){
        cin >> w >> v;
        value[w-base].push_back(v);
    }
    for(int i = 0; i < 4; i++)  sort(value[i].rbegin(), value[i].rend());

    int ans = 0;
    for(int a = 0; a <= value[0].size(); a++){
        for(int b = 0; b <= value[1].size(); b++){
            for(int c = 0; c <= value[2].size(); c++){
                for(int d = 0; d <= value[3].size(); d++){
                    if((ll)base*(a + b + c + d) + b + 2*c + 3*d > W)   break;
                    int tmp = 0;
                    for(int x = 0; x < a; x++)  tmp += value[0][x];
                    for(int x = 0; x < b; x++)  tmp += value[1][x];
                    for(int x = 0; x < c; x++)  tmp += value[2][x];
                    for(int x = 0; x < d; x++)  tmp += value[3][x];
                    ans = max(ans, tmp);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}