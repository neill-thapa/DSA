#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    // Upper part
    for(int i = 0; i < n; i++) {

        // Leading spaces
        for(int j = 0; j < n - i - 1; j++)
            cout << " ";

        if(i == 0) {
            cout << "*";
        } else {
            cout << "*";

            // Inside spaces
            for(int j = 0; j < 2*i - 1; j++) {
                cout << " "; 
            }

            cout << "*";
        }

        cout << endl;
    }

    // Lower part
    for(int i = n - 2; i >= 0; i--) {

        for(int j = 0; j < n - i - 1; j++)
            cout << " ";

        if(i == 0) {
            cout << "*";
        } else {
            cout << "*";

            for(int j = 0; j < 2*i - 1; j++) {
                cout << " ";
            }

            cout << "*";
        }

        cout << endl;
    }

    return 0;
}