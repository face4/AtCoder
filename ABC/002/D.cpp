#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    bool connect[13][13] = {};
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        connect[x][y] = connect[y][x] = true;
    }

    int ans = 1;
    for(int i = 1; i < 1<<n; i++){
        vector<int> people;
        int tmp = i, pos = 1;
        while(tmp > 0){
            if(tmp & 1) people.push_back(pos);
            tmp = tmp >> 1;
            pos++;  
        }

        int num = people.size();
        bool judge = true;

        for(int i = 0; i < num; i++){
            for(int j = i+1; j < num; j++){
                if(!connect[people[i]][people[j]])  judge = false;
            }
        }

        if(judge)   ans = max(ans,num);
    }

    cout << ans << endl;

    return 0;
}