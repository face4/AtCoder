#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void init(vector<T> &v){
    int h = v.size();
    int w = v[0].size();
    for(int i = 0; i < h; i++){
        for(int j = 1; j < w; j++){
            v[i][j] += v[i][j-1];
        }
    }
    for(int j = 0; j < w; j++){
       for(int i = 1; i < h; i++){
           v[i][j] += v[i-1][j];
       } 
    }
}

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> v(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char c; cin >> c;
            v[i][j] = c-'0';
        }
    }
    init(v);
    auto f = [&](int i, int j, int k, int l)->int{
        return v[k][l]-(i==0 ? 0 : v[i-1][l])-(j==0 ? 0 : v[k][j-1])+(i>0&&j>0 ? v[i-1][j-1] : 0);
    };
    int ret = 1<<30;
    for(int i = 0; i < 1<<(h-1); i++){
        int tmp = 0;
        vector<int> split;
        split.push_back(0);
        for(int j = 0; j < h-1; j++){
            if((i>>j)&1){
                tmp++;
                split.push_back(j+1);
            }
        }
        if(split.back() != h)   split.push_back(h);
        bool valid = true;
        int wpos = 0;
        while(wpos < w){
            int nw = w;
            for(int j = 0; j+1 < split.size(); j++){
                int from = split[j], to = split[j+1];
                if(f(from, wpos, to-1, wpos) > k){
                    valid = false;
                    break;
                }
                int npos = wpos;
                while(npos+1 < w && f(from, wpos, to-1, npos+1) <= k)   npos++;
                nw = min(nw, npos+1);
            }
            if(!valid)  break;
            tmp += (nw!=w);
            wpos = nw;
        }
        if(valid)   ret = min(ret, tmp);
    }
    cout << ret << endl;
    return 0;
}