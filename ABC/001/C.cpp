#include<iostream>
#include<cmath>
using namespace std;

string degree(int d){
    if(d >= 3487.5)         return "N";
    else if(d >= 3262.5)    return "NNW";
    else if(d >= 3037.5)    return "NW";
    else if(d >= 2812.5)    return "WNW";
    else if(d >= 2587.5)    return "W";
    else if(d >= 2362.5)    return "WSW";
    else if(d >= 2137.5)    return "SW";
    else if(d >= 1912.5)    return "SSW";
    else if(d >= 1687.5)    return "S";
    else if(d >= 1462.5)    return "SSE";
    else if(d >= 1237.5)    return "SE";
    else if(d >= 1012.5)    return "ESE";
    else if(d >= 787.5)     return "E";
    else if(d >= 562.5)     return "ENE";
    else if(d >= 337.5)     return "NE";
    else if(d >= 112.5)     return "NNE";
    else                    return "N";
}

int wind(int d){
    double x = round((double)d / 60.0 * 10.0) /10.0;
    if(x >= 32.7)       return 12;
    else if(x >= 28.5)  return 11;
    else if(x >= 24.5)  return 10;
    else if(x >= 20.8)  return 9;
    else if(x >= 17.2)  return 8;
    else if(x >= 13.9)  return 7;
    else if(x >= 10.8)  return 6;
    else if(x >= 8.0)   return 5;
    else if(x >= 5.5)   return 4;
    else if(x >= 3.4)   return 3;
    else if(x >= 1.6)   return 2;
    else if(x >= 0.3)   return 1;
    else                return 0;
}

int main(){
    int deg, dis;
    cin >> deg >> dis;

    string dir = degree(deg);
    int w = wind(dis);

    if(w){
        cout << dir << " " << w << endl;
    }else{
        cout << "C " << w << endl;
    }
}