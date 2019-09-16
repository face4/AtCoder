#include<iostream>
#include<vector>
using namespace std;

// １００％は理解できていない
vector<int> zalgo(string s){
    vector<int> prefix(s.size());
    for(int i = 1, j = 0; i < s.size(); i++){
        if(i + prefix[i-j] < j + prefix[j]){
            prefix[i] = prefix[i-j];
        }else{
            int k = max(0, j+prefix[j]-i);
            while(i + k < s.size() && s[k] == s[i+k])   k++;
            prefix[i] = k;
            j = i;
        }
    }
    prefix[0] = s.size();
    return prefix;
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<int> tmp = zalgo(s.substr(i));
        for(int j = 0; j < n-i; j++){
            if(tmp[j] <= j) ans = max(ans, tmp[j]);
        }
    }
    cout << ans << endl;
    return 0;
}