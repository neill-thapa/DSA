#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    // Upper half
    for(int i = 0; i < n; i++) {

        // Left stars
        for(int j = 0; j <= i; j++)
            cout << "*";

        // Middle spaces
        for(int j = 0; j < 2 * (n - i - 1); j++)
            cout << " ";

        // Right stars
        for(int j = 0; j <= i; j++)
            cout << "*";

        cout << endl;
    }

    // Lower half
    for(int i = n - 2; i >= 0; i--) {

        for(int j = 0; j <= i; j++)
            cout << "*";

        for(int j = 0; j < 2 * (n - i - 1); j++)
            cout << " ";

        for(int j = 0; j <= i; j++)
            cout << "*";

        cout << endl;
    }

    return 0;
}