#include<iostream>
#include<iomanip>
using namespace std;
double search (int numLightBall, double height) {
double firstLamp, secondLamp, thirdLamp, left = 0, result;
double right = height;
while ((right - left) > (0.001) / (numLightBall - 1)) {
    bool F = true;
    double mid = (right + left) / 2;
    firstLamp = height;
    secondLamp = mid;
    for (int i = 3; i <= numLightBall && F == true; i++) {
        thirdLamp = 2 * secondLamp - firstLamp + 2;
        if (thirdLamp < 0) {
            thirdLamp = 0;
            F = false;
        }
        firstLamp = secondLamp;
        secondLamp = thirdLamp;
    }
    if (F) {
        right = mid;
        result = secondLamp;
    }
    else
        left = mid;
}
return result;
};
int main() {
    int n;
    double a;
    cin >> n >> a;
    cout << fixed << setprecision(2) << search(n,a);
    return 0;
}
