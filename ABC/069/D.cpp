#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int h, w, n, a;
    cin >> h >> w >> n;

    vector<int> line;
    for(int i = 1; i <= n; i++){
        cin >> a;
        for(int j = 0; j < a; j++)  line.push_back(i);
    }

    for(int begin = w; begin < h*w; begin += 2*w)   reverse(line.begin()+begin, line.begin()+begin+w);
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(j)   cout << " ";
            cout << line[i*w + j];
        }
        cout << endl;
    }

    return 0;
}