#include<iostream>
using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    bool water[31] = {};
    bool sugar[3001] = {};

    water[0] = sugar[0] = true;
    for(int i = 0; i < 31; i++){
        if(water[i] && i+a < 31)    water[i+a] = true;
        if(water[i] && i+b < 31)    water[i+b] = true;
    }
    for(int i = 0; i < 3001; i++){
        if(sugar[i] && i+c < 3001)  sugar[i+c] = true;
        if(sugar[i] && i+d < 3001)  sugar[i+d] = true;        
    }

    double maxRate = -1;
    int answater = 0, anssugar = 0;

    for(int i = 1; i <= f/100; i++){
        if(water[i]){
            int tmpsugar = i*e;
            for(;tmpsugar >= 0;tmpsugar--){
                if(sugar[tmpsugar] && tmpsugar+i*100 <= f) break;
            }
            
            if(tmpsugar == -1)  continue;

            if(100.0*tmpsugar/(i*100.0 + tmpsugar) > maxRate){
                maxRate = 100.0*tmpsugar/(i*100.0 + tmpsugar);
                answater = i*100;
                anssugar = tmpsugar;
            }
        }
    }

    cout << answater+anssugar << " " << anssugar << endl;

    return 0;
}