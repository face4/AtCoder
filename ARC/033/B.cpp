#include<iostream>
#include<map>
#include<iomanip>
using namespace std;

int main(){
    int na, nb, x;
    cin >> na >> nb;

    map<int,int> m;

    for(int i = 0; i < na; i++){
        cin >> x;
        m[x]++;
    }

    int uni, intersec = 0;

    for(int i = 0; i < nb; i++){
        cin >> x;
        if(m.count(x))  intersec++;
        m[x]++;
    }

    uni = m.size();

    cout << fixed << setprecision(7) << intersec / (double)uni << endl;

    return 0; 
}