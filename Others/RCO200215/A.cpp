#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<random>
#include<chrono>
using namespace std;

int n, w, k, v;
int col[1000], val[10000], ans[1000];
int score = 0;

double T = 25.0;
double T_END = 15.0;
double T_FACTOR = 0.99999;

int ind[8], r[6][125];

int calc(){
    memset(ind, 0, sizeof(ind));
    memset(r, 0, sizeof(r));
    for(int i = 0; i < n; i++){
        r[col[i]][ind[ans[i]]++] += val[i];
    }
    int ret = 0;
    for(int i = 0; i < 125; i++){
        int ma = 0;
        for(int j = 0; j < 6; j++){
            if(ma < r[j][i])    ma = r[j][i];
        }
        ret += ma;
    }
    return ret;
}

void answer(){
    for(int i = 0; i < n; i++)  cout << ans[i] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    auto start = std::chrono::system_clock::now(); 
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<int> rand1000(0,999);
    uniform_real_distribution<double> prob(0.0, 1.0);

    cin >> n >> w >> k >> v;

    // initialize
    for(int i = 0; i < n; i++){
        ans[i] = i/125;
        cin >> col[i] >> val[i];
    }

    // int count = 0, mi = 1<<30, ma = -(1<<30);
    while(true){
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start).count();
        if(now > 1993)  break;
        // count++;
        int X = rand1000(mt);
        int Y, step = 10;
        while(step--){
            Y = rand1000(mt);
            if(col[X] != col[Y] || ans[X] != ans[Y])    break;
        }
        swap(ans[X], ans[Y]);
        int tmp = calc();
        int diff = tmp-score;
        // if(count-1) ma = max(diff, ma);
        // if(count-1) mi = min(diff, mi);
        if(diff >= 0 || prob(mt) < 1+diff/T){
            score = tmp;
        }else{
            swap(ans[X], ans[Y]);
        }
        T *= T_FACTOR;
    }
    // cout << count << endl;
    // cout << T << endl;
    // cout << ma << " " << mi << endl;
    answer();

	return 0;
}