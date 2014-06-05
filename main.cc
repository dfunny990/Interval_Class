#include "Interval.h"
    #include <iostream>
    #include <cassert>

    using namespace std;

    int main() {
        const Interval a(18,49), b(3, 9), c(-10,-2);
        cout << "Expect [25,56]: "    << 7+a << endl;
        cout << "Expect [21,58]: "    << a+b << endl;
        cout << "Expect [9,46]: "     << a-b << endl;
        cout << "Expect [-490,-36]: " << a*c << endl;
        cout << "Expect [-24,-1]: "   << a/c << endl;
        cout << "Expect [-16,-6]: "   << a/-3 << endl;
        cout << "Expect [10,30]: "    << 90/b << endl;

        assert(Interval(1,3) == Interval(1, 3));

        assert(Interval(1,3) < Interval(5, 1000));
        assert(!(Interval(1,3) < Interval(2, 4)));

        assert(Interval(1,3) <= Interval(3, 1000));
        assert(!(Interval(1,3) < Interval(3, 1000)));

        assert(Interval(1,9) != Interval(1, 3));
        assert(Interval(1,3) != Interval(5, 9));

    #define deny(expression) assert(!(expression))  // Opposite of assert

        const Interval alpha(1,5), beta(3,7);
        deny(alpha < beta);
        deny(alpha <= beta);
        deny(alpha > beta);
        deny(alpha >= beta);
        deny(alpha == beta);

        cout << "Done.\n";

        return 0;
    }