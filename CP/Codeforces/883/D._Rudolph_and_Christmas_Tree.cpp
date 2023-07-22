
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, d, h;
        cin >> n >> d >> h;

        vector<int> y(n);
        for (int i = 0; i < n; i++) {
            cin >> y[i];
        }

        double area = 0.5 * d * h;
        double ans = area;

        for (int i = 1; i < n; i++) {
            double height = min(static_cast<double>(y[i] - y[i - 1]) / h, 1.0);
            ans += area * (1.0 - (1.0 - height) * (1.0 - height));
        }

        cout.precision(9);  // Increase precision to 9 decimal places
        cout << fixed << ans << endl;
    }

    return 0;
}

