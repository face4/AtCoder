#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int sx, sy, gx, gy, t, v;
    cin >> sx >> sy >> gx >> gy >> t >> v;

    int n;
    cin >> n;

    bool judge = false;
    int x, y;
    double move = (double)t*v;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        double dist = sqrt(pow(x-sx, 2.0) + pow(y-sy, 2.0)) + 
                        sqrt(pow(gx-x, 2.0) + pow(gy-y, 2.0));
        if(dist <= move) judge = true;
    }

    if(judge){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}