#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    
    int appear[26] = {};
    char c;
    for(int i = 0; i < w*h; i++){
        cin >> c;
        appear[c-'a']++;
    }

    vector<int> v, ans;
    for(int i = 0; i < 26; i++) if(appear[i])   v.push_back(appear[i]);

    sort(v.begin(), v.end());
    int total = h*w;

    if(h%2 == 1 && w%2 == 1){
        ans.push_back(1);
        total--;
        for(int i = 0; i < h/2+w/2; i++)    ans.push_back(2), total -= 2;
        while(total > 0)    ans.push_back(4), total -= 4;
    }else if(h%2 == 0 && w%2 == 0){
        while(total > 0)    ans.push_back(4), total -= 4;
    }else{
        if(h%2 == 0)    swap(w,h);
        for(int i = 0; i < w/2; i++)    ans.push_back(2), total -= 2;
        for(int i = 0; i < w/2 * (h/2); i++)    ans.push_back(4), total -= 4;
    }

    // write here!

    return 0;
}

https://beta.atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_c