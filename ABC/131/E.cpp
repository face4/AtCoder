#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    if(n == 2){
        if(k == 0){
            cout << 1 << endl;
            cout << "1 2" << endl;
        }else{
            cout << -1 << endl;
        }
        return 0;
    }

    vector<vector<bool>> g(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++){
        if(i == 1)  continue;
        g[i][1] = g[1][i] = true;
    }

    int res = n-2 + (n-2)*(n-2-1)/2;
    
    if(res < k){
        cout << -1 << endl;
        return 0;
    }

    int ind1 = 2, ind2 = 2;
    while(res != k){
        if(ind1 != n){
            g[0][ind1] = g[ind1][0] = true;
            res--;
            ind1++;
            continue;
        }else{
            bool path = false;
            for(int next = ind2+1; next < n; next++){
                if(!g[ind2][next]){
                    g[ind2][next] = g[next][ind2] = true;
                    res--;
                    path = true;
                    break;
                }
            }
            if(!path)   ind2++;
            continue;
        }
    }

    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(g[i][j]) vp.push_back({i+1,j+1});
        }
    }
    cout << vp.size() << endl;
    for(int i = 0; i < vp.size(); i++){
        cout << vp[i].first << " " << vp[i].second << endl;
    }

    return 0;
}