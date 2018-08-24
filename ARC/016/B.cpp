#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 0;
    bool push[9] = {};

    string line;

    for(int i = 0; i < n; i++){
        cin >> line;
        for(int j = 0; j < 9; j++){
            if(line[j] == 'x'){
                ans++;
                push[j] = false;
            }else if(line[j] == 'o'){
                if(!push[j]){
                    ans++;
                    push[j] = true;
                }
            }else{
                push[j] = false;
            }
        }
    }

    cout << ans << endl;

    return 0;
}