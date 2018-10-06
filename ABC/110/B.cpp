#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    int x[n], y[m];
    for(int i = 0; i < n; i++)  cin >> x[i];
    for(int i = 0; i < m; i++)  cin >> y[i];
    sort(x, x+n);
    sort(y, y+m);

    bool war = true;
    for(int i = X+1; i <= Y; i++){
        if(x[n-1] < i && i <= y[0]) war = false;
    }

    if(war) cout << "War" << endl;
    else    cout << "No War" << endl;

    return 0;
}
