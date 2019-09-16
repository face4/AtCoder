#include<iostream>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

// 2*k * 2*kのグリッド上でk * kのグリッドによる区間可算を行う
// 累積和を使う
int main(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> sum(2*k, vector<int>(2*k, 0));
    for(int i = 0; i < n; i++){
        int x, y;   char c;
        cin >> x >> y >> c;
        if(c == 'W')    y += k;
        x %= 2*k, y %= 2*k;
        x -= k-1, y -= k-1;
        for(int a = -2; a <= 2; a++){
            for(int b = -2; b <= 2; b++){
                if((abs(a)+abs(b))%2)   continue;
                // 全て閉区間、左下(si,sj)右上(ti,tj)の1辺kの正方形
                int si = x+a*k, sj = y+b*k;
                int ti = si+k-1, tj = sj+k-1; 
                if(si > 2*k || sj > 2*k || ti < 0 || tj < 0)    continue;
                si = max(si, 0);    ti = min(ti, 2*k-1);
                sj = max(sj, 0);    tj = min(tj, 2*k-1);
                if(inRange(si,0,2*k)&&inRange(sj,0,2*k))    sum[si][sj]++;
                if(inRange(ti+1,0,2*k)&&inRange(sj,0,2*k))    sum[ti+1][sj]--;
                if(inRange(si,0,2*k)&&inRange(tj+1,0,2*k))    sum[si][tj+1]--;
                if(inRange(ti+1,0,2*k)&&inRange(tj+1,0,2*k))    sum[ti+1][tj+1]++;
            }
        }
    }
    for(int i = 0; i < 2*k; i++){
        for(int j = 1; j < 2*k; j++){
            sum[i][j] += sum[i][j-1];
        }
    }
    for(int j = 0; j < 2*k; j++){
        for(int i = 1; i < 2*k; i++){
            sum[i][j] += sum[i-1][j];
        }
    }
    
    int ans = 0;
    for(int i = 0; i < 2*k; i++){
        for(int j = 0; j < 2*k; j++){
            ans = max(ans, sum[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}