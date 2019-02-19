// なにもわからない...
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

struct match{
    int num, use;
    bool operator<(const match other) const{
        if(use != other.use)    return use < other.use;
        else                    return num > other.num;
    }
};

string enc(int x){
    char c = '0'+x;
    string ret({c});
    return ret;
}

int a[10] = {0,2,5,5,4,5,6,3,7,6};
int n, m;
vector<int> ans;
vector<match> v;
string fin = "";
bool first = true;
int len = 0;

void dfs(int cur, int res){
    if(cur == v.size()){
        if(res != 0)    return;
        string ret = "";
        for(int i = 0; i < v.size(); i++){
            string s = enc(v[i].num);
            for(int j = 0; j < ans[i]; j++) ret += s;
        }
        sort(ret.begin(), ret.end());
        reverse(ret.begin(), ret.end());
        if(first){
            len = ret.length();
            first = false;
        }else{
            if(ret.length() < len){
                cout << fin << endl;
                exit(0);
            }
        }
        if(fin.length() < ret.length()) fin = ret;
        else if(fin.length()==ret.length() && fin < ret)    fin = ret;
        return;
    }

    for(int j = res/v[cur].use; j >= 0; j--){
        ans.push_back(j);
        dfs(cur+1, res-j*v[cur].use);
        ans.pop_back();
    }
}

// TLEしそう.
int main(){
    cin >> n >> m;
    map<int, match> ma;
    for(int i = 0; i < m; i++){
        int x;  cin >> x;
        match tmp({x, a[x]});
        if(ma.count(a[x])){
            if(x > ma[a[x]].num){
                ma[a[x]] = tmp;
            }
        }else{
            ma[a[x]] = tmp;
        }
    }

    for(auto p : ma){
        v.push_back(p.second);
    }

    sort(v.begin(), v.end());

    dfs(0, n);

    cout << fin << endl;

    return 0;
}
