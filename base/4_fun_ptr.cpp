#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int (*operationPtr)(int, int);
    operationPtr = &add;
    int result = operationPtr(10, 5);
    cout << "result = " << result << endl;

    operationPtr = &subtract;
    result = operationPtr(10, 5);
    cout << "result = " << result << endl;

    return 0;
}