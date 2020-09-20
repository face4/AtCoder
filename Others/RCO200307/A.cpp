#include<iostream>
#include<chrono>
#include<random>
#include<vector>
#include<algorithm>
using namespace std;

int dice[6] = {1, 2, 3, 4, 5, 6};
int val[501] = {};
bool know[501] = {};
int n, m;

int f(int pos){
    int ret = 0;
    for(int i = 0; i < 6; i++){
        int npos = pos+dice[i];
        if(npos > n)    npos = n - (npos-n);
        ret += val[npos];
    }
    return ret;
}

int main(){
    cin >> n >> m;
    know[0] = true;
    know[n] = 5000;
    for(int i = 0; i < 6; i++)  know[n-i] = true;
    for(int i = 0; i <= n; i++) if(!know[i])    val[i] = 20000;

    auto start = std::chrono::system_clock::now(); 
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<int> rand6(0,5);
    
    int pos = 0;

    while(m--){
        int chpos = -1, to = -1, score = 0;
        for(int i = 0; i < 6; i++){
            int bef = dice[i];
            for(int j = 1; j <= 6; j++){
                dice[i] = j;
                int tmp = f(pos);
                if(tmp > score){
                    score = tmp;
                    chpos = i;
                    to = j;
                }
            }
            dice[i] = bef;
        }
        dice[chpos] = to;

        for(int i = 0; i < 6; i++) cout << dice[i] << " \n"[i==5];
        cout << flush;
        
        int d, v, x;
        cin >> d >> v >> x;
        
        know[x] = true;
        val[x] = v;

        pos = x%n;
    }

    return 0;
}