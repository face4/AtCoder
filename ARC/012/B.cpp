#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    double va, vb, l;
    cin >> n >> va >> vb >> l;

    for(int i = 0; i < n; i++){
        double t = l/va;
        l = t * vb;
    }

    cout << fixed << setprecision(7) << l << endl;

    return 0;
}