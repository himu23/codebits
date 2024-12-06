#include <simplecpp>

main_program {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
    } else {
        int m = n;
        int a = 0;

        while (m > 0) {
            m = m / 2;
            a++;
        }

        m = n;
        int divisor = 1;
        for (int i = 1; i < a; i++) {
            divisor *= 2;
        }

        for (int i = 0; i < a; i++) {
            cout << (m / divisor);
            m = m % divisor;
            divisor = divisor / 2;
        }
    }
}

