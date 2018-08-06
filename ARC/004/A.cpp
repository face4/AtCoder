#include<iostream>
#include<cmath>
using namespace std;

int x[100], y[100];

double dist(int i, int j){
    int diffx = x[i]-x[j];
    int diffy = y[i]-y[j];
    return sqrt(pow(diffx,2.0)+pow(diffy,2.0)); 
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    double ans = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            ans = max(ans, dist(i,j));
        }
    }

    cout << ans << endl;

    return 0;
}