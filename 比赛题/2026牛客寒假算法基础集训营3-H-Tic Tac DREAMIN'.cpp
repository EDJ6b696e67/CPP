#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"
#define area 2.0

/*
三点 P (x, 0)、A (xa, ya)、B (xb, yb) 构成的三角形面积公式推导：
向量PA=(xa​−x,ya​)，向量PB=(xb​−x,yb​)
三角形面积 = 0.5×∣PA×PB∣（叉积的绝对值的一半）
展开叉积：PA×PB=(xa​−x)yb​−(xb​−x)ya​=xa​yb​−xb​ya​+x(ya​−yb​)
要求面积 = 2，即：∣xa​yb​−xb​ya​+x(ya​−yb​)∣=4
*/

signed main(){
    double xa, ya, xb, yb;
    if(!(cin >> xa >> ya >> xb >> yb)) return 0;
    double C = xa * yb - xb * ya;
    double D = ya - yb;
    const double EPS = 1e-7;
    if (fabs(D) < EPS) {
        double real_area = 0.5 * fabs((xa - xb) * ya);
        if (fabs(real_area - 2.0) <= 1e-3) {
            cout << fixed << setprecision(8) << xa << endl;
        } else {
            cout << "no answer" << endl;
        }
        return 0;
    }
    double x = (area * 2.0 - C) / D;
    cout << fixed << setprecision(8) << x << endl;
    return 0;
}