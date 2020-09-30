#include<iostream>
using namespace std;

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    char c[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> c[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < 1<<h; i++){
        for(int j = 0; j < 1<<w; j++){
            int count = 0;
            for(int I = 0; I < h; I++){
                if(i>>I&1)  continue;
                for(int J = 0; J < w; J++){
                    if(j>>J&1)  continue;
                    count += c[I][J]=='#';
                }
            }
            ans += (count==k);
        }
    }
    cout << ans << endl;
    return 0;
}