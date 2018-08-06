#include<iostream>
using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int x){
    if(x%4 == 0 && x%100 != 0)  return true;
    if(x%400 == 0) return true;
    return false;
}

int main(){
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);

    bool found = false;
    while(1){
        if(y%m == 0){
            int ym = y/m;
            for(;d <= days[m] + (m == 2 && isLeap(y)); d++){
                if(ym%d == 0){
                    found = true;
                    break;
                }
            }
        }

        if(found){
            break;
        }else{
            if(m == 12){
                y++;
            }
            m = m%12 + 1;
            d = 1;
        }
    }

    printf("%04d/%02d/%02d\n", y, m, d);

    return 0;
}