#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;

struct SEG{
private:
    vector<double> a, b;
    int n;
public:
    SEG(int si){
        n = 1;
        while(n < si)  n *= 2;
        a.resize(2*n-1, 1);
        b.resize(2*n-1, 0);
    }
    void update(int x, double av, double bv){
        x += n-1;
        a[x] = av, b[x] = bv;
        while(x > 0){
            x = (x-1)/2;
            double la = a[2*x+1], lb = b[2*x+1];
            double ra = a[2*x+2], rb = b[2*x+2];
            a[x] = la*ra;
            b[x] = lb*ra + rb;
        }
    }
    double calc(){
        return a[0] + b[0];
    }
};

int main(){
    ll n;
    int m;
    cin >> n >> m;
    vector<ll> p(m), x;
    vector<double> a(m), b(m);
    for(int i = 0; i < m; i++){
        cin >> p[i] >> a[i] >> b[i];
        x.push_back(p[i]);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    int siz = x.size();
    SEG seg(siz);
    double ma = 1.0, mi = 1.0;
    for(int i = 0; i < m; i++){
        seg.update(lower_bound(x.begin(),x.end(),p[i])-x.begin(), a[i], b[i]);
        double val = seg.calc();
        ma = max(ma, val);
        mi = min(mi, val);
    }
    cout << fixed << setprecision(12) << mi << endl;
    cout << ma << endl;
    return 0;
}
