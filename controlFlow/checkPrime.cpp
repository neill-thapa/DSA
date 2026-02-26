// check if the number is prime or composite
#include <iostream>
using namespace std;

void checkPrime(int n);

int main(void) {
    int number;
    cout << "Enter the number: ";
    cin >> number;

    checkPrime(number);

    return 0;
}

void checkPrime(int n) {
    if (n <= 1) {
        cout << "Neither Prime nor Composite." << endl;
        return;
    }

    bool isPrime = true; // assume it is prime

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = false; 
            break;
        }
    }

    if (!isPrime) {
        cout << "The number is Composite." << endl;
    }
    else {
        cout << "The number is Prime." << endl;
    }

    return;
}