#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<int> l;
int n, in[3];
vector<int> v[4];
int ans = 1<<30;

void dfs(int pos){
    if(pos == n){
        int tmp = 0, make[3] = {};
        for(int i = 0; i < 3; i++){
            tmp += max(0, (int)(v[i].size())-1)*10;
            for(int j : v[i])   make[i] += l[j];
            if(make[i] == 0)    return;
        }
        sort(in, in+3);
        do{
            ans = min(ans, tmp+abs(in[0]-make[0])+abs(in[1]-make[1])+abs(in[2]-make[2]));
        }while(next_permutation(in, in+3));
        return;
    }

    for(int i = 0; i < 4; i++){
        v[i].push_back(pos);
        dfs(pos+1);
        v[i].pop_back();
    }
}

int main(){
    cin >> n >> in[0] >> in[1] >> in[2];
    l.resize(n);
    for(int i = 0; i < n; i++)  cin >> l[i];
    dfs(0);
    cout << ans << endl;
    return 0;
}