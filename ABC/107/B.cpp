#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

char mat[100][100];

int main(){
    int h, w;
    cin >> h >> w;

    vector<string> v;
    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    bool height[100] = {}, width[100] = {};
    for(int i = 0; i < h; i++){
        if(count(v[i].begin(), v[i].end(), '.') == w){
            height[i] = true;
        }
    }

    for(int j = 0; j < w; j++){
        int cnt = 0;
        for(string t : v){
            if(t[j] == '.') cnt++;
        }
        if(cnt == h)    width[j] = true;
    }

    for(int i = 0; i < h; i++){
        if(height[i])   continue;
        for(int j = 0; j < w; j++){
            if(width[j])    continue;
            cout << v[i][j];
        }
        cout << endl;
    }

    return 0;
}