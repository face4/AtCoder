#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);

    bool rain[12*24] = {};
    int s, e;

    for(int i = 0; i < n; i++){
        scanf("%d-%d\n", &s, &e);

        s = s/100*100 + (s%100)/5*5;
        e = e/100*100 + (e%100 + 4)/5 * 5;        
        if(e%100 == 60) e = e-60+100;

        s = s/100*12 + s%100/5;
        e = e/100*12 + e%100/5;

        for(int j = s; j < e; j++){
            rain[j] = true;   
        }
    }

    bool inrain = false;
    for(int i = 0; i < 12*24; i++){
        if(rain[i] && inrain){
            // do nothing.
        }else if(rain[i] && !inrain){
            inrain = true;
            int output = i*5;
            int hour = output/60;
            output = hour*100 + output-hour*60;
            cout << setfill('0') << right << setw(4) << output << "-";
        }else if(!rain[i] && inrain){
            inrain = false;
            int output = i*5;
            int hour = output/60;
            output = hour*100 + output-hour*60;
            cout << setfill('0') << right << setw(4) << output << endl;
        }else if(!rain[i] && !inrain){
            // do nothing.
        }
    }

    if(inrain)  cout << "2400" << endl;

    return 0;
}