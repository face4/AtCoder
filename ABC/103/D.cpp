#include<iostream>
#include<stack>
#include<set>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> before(n+1), after(n+1);

    int a, b;
    int number = 1;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        before[a].push_back(number);
        after[b].push_back(number);
        number++;
    }

    set<int> danger, safe;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(after[i].size() != 0){
            bool breakbridge = false;
            for(int j = 0; j < after[i].size(); j++){
                int x = after[i][j];
                if(danger.find(x) != danger.end()){
                    breakbridge = true;
                }else{
                    // already separated by broken bridges
                }
            }
            if(breakbridge){
                ans++;
                danger.clear();
            }
        }

        if(before[i].size() != 0){
            for(int j = 0; j < before[i].size(); j++){
                danger.insert(before[i][j]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}