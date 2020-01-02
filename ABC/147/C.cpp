#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v[n];
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        while(x-- > 0){
            int a, b;
            cin >> a >> b;
            v[i].push_back({a-1,b});
        }
    }
    int ret = 0;
    for(int i = 1; i < 1<<n; i++){
        vector<int> stat(n, 0);
        int tmp = 0;
        for(int j = 0; j < n; j++){
            if((i>>j)&1)    stat[j] = 1, tmp++;
            else            stat[j] = -1;
        }
        bool valid = true;
        for(int j = 0; j < n; j++){
            if((i>>j)&1){
                for(pair<int,int> p : v[j]){
                    valid &= (p.second==0 && stat[p.first]==-1) || (p.second==1 && stat[p.first]==1);
                }
            }
        }
        if(valid)   ret = max(ret, tmp);
    }
    cout << ret << endl;
    return 0;
}