#include <iostream>

using namespace std;

int main() {
    int pointsInsideCircle = 0;
    for (int i = 0; i < 10000; ++i) {
        double x = -1 + (2.0 * rand()) / RAND_MAX;
        double y = -1 + (2.0 * rand()) / RAND_MAX;
        if (x * x + y * y <= 1) pointsInsideCircle++;
    }
    cout << "Probability: " << static_cast<double>(pointsInsideCircle) / 10000 << endl;
    return 0;
}
