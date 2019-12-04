#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> v[10];
    for(int i = 0; i < n; i++){
        v[s[i]-'0'].push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                int pos = 0;
                pos = lower_bound(v[i].begin(), v[i].end(), pos)-v[i].begin();
                if(pos == v[i].size())  continue;
                pos = v[i][pos]+1;
                pos = lower_bound(v[j].begin(), v[j].end(), pos)-v[j].begin();
                if(pos == v[j].size())  continue;
                pos = v[j][pos]+1;
                pos = lower_bound(v[k].begin(), v[k].end(), pos)-v[k].begin();
                if(pos == v[k].size())  continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}