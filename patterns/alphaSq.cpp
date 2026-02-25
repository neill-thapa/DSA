#include <iostream>
using namespace std;

int main(void) {
    int size;
    cout << "Enter the size of square: ";
    cin >> size;

    for (int i = 1; i <= size; i++) {
        char ch = 'A';
        for (int j = 1; j <= size; j++) {
            cout << ch << " ";
            ch = ch + 1; // update the character with its ASCII values
        }
        cout << endl;
    }

    return 0;
}