#include <iostream>
using namespace std;

int main(void) {
    int size;
    cout << "Enter the size of left aligned triangle: ";
    cin >> size;

    int num = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}