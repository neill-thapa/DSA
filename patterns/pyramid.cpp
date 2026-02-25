#include <iostream>
using namespace std;

int main(void) {
    int height;
    cout << "Enter the height of the pyramid: ";
    cin >> height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i - 1; j++) {
            cout << " ";
        }

        for (int k = 1; k <= i + 1; k++) {
            cout << k; 
        }

        for (int l = i; l >= 1; l-- ) {
            cout << l;
        }

        cout << endl;
    }

    return 0;
}