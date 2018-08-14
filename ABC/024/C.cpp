#include<iostream>
using namespace std;
#define inRange(x, a, b) a <= x && x <= b

int main(){
    int n, d, k;
    scanf("%d %d %d\n", &n, &d, &k);

    int l[d], r[d];
    for(int i = 0; i < d; i++){
        scanf("%d %d\n", l+i, r+i);
    }

    int s, t;
    for(int i = 0; i < k; i++){
        scanf("%d %d\n", &s, &t);
        int pos = s, day;
        for(day = 0;; day++){
            if(inRange(pos, l[day], r[day])){
                if(inRange(t, l[day], r[day])){
                    // reached.
                    break;
                }

                if(pos < t){
                    pos = r[day];
                }else{
                    pos = l[day];
                }
            }
        }

        printf("%d\n", day+1);
    }

    return 0;
}