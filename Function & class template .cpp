#include <iostream>
using namespace std;

// Function template to find the maximum of three values
template <typename T>
T findMax(T a, T b, T c) {
    T max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

// Class template for Calculator
template <typename T>
class Calculator {
private:
    T num1, num2;
public:
    Calculator(T n1, T n2) : num1(n1), num2(n2) {}

    T add() {
        return num1 + num2;
    }

    T subtract() {
        return num1 - num2;
    }
};

int main() {
    // Demonstrate findMax
    cout << "Maximum of 3, 7, 5 (int): " << findMax(3, 7, 5) << endl;
    cout << "Maximum of 4.2, 1.8, 3.5 (float): " << findMax(4.2f, 1.8f, 3.5f) << endl;
    cout << "Maximum of 'a', 'z', 'm' (char): " << findMax('a', 'z', 'm') << endl;

    // Demonstrate Calculator
    Calculator<int> intCalc(10, 5);
    cout << "\nInteger Calculator:\n";
    cout << "10 + 5 = " << intCalc.add() << endl;
    cout << "10 - 5 = " << intCalc.subtract() << endl;

    Calculator<double> doubleCalc(5.5, 2.2);
    cout << "\nDouble Calculator:\n";
    cout << "5.5 + 2.2 = " << doubleCalc.add() << endl;
    cout << "5.5 - 2.2 = " << doubleCalc.subtract() << endl;

    return 0;
}