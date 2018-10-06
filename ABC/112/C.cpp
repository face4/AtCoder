#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int x[n], y[n], h[n];
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i] >> h[i];

    int select;
    for(select = 0;;select++){
        if(h[select] != 0)  break;
    }

    int ax, ay, tmph, pos;
    for(ax = 0; ax <= 100; ax++){
        for(ay = 0; ay <= 100; ay++){
            tmph = h[select] + abs(ax-x[select]) + abs(ay-y[select]);
            if(tmph < 1)    continue;
            for(pos = 0; pos < n; pos++){
                if(max(tmph-abs(ax-x[pos])-abs(ay-y[pos]), 0) != h[pos])  break;
            }
            if(pos == n)    break;
        }
        if(pos == n)    break;
    }

    cout << ax << " " << ay << " " << tmph << endl;

    return 0;
}