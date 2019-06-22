#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v[m];
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        while(k-- > 0){
            int x;
            cin >> x;
            v[i].push_back(--x);
        }
    }
    vector<int> p(m);
    for(int i = 0; i < m; i++)  cin >> p[i];
    int ans = 0;
    for(int i = 0; i < 1<<n; i++){
        vector<int> sw(n, 0);
        for(int j = 0; j < n; j++){
            if((i>>j)&1)    sw[j] = 1;
        }
        bool judge = true;
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int k = 0; k < v[j].size(); k++)    sum += sw[v[j][k]];
            judge &= ((sum%2)==p[j]);
        }
        if(judge)   ans++;
    }
    cout << ans << endl;
    return 0;
}