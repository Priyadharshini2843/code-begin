#include <iostream>
#include <stdexcept>  // For standard exception classes
using namespace std;

int main() {
    int numerator, denominator;
    
    try {
        cout << "Enter numerator: ";
        if (!(cin >> numerator)) {
            throw invalid_argument("Invalid input for numerator.");
        }

        cout << "Enter denominator: ";
        if (!(cin >> denominator)) {
            throw invalid_argument("Invalid input for denominator.");
        }

        if (denominator == 0) {
            throw runtime_error("Division by zero is not allowed.");
        }

        double result = static_cast<double>(numerator) / denominator;
        cout << "Result = " << result << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Invalid input error: " << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << endl;
    }
    catch (...) {
        cerr << "An unknown error occurred." << endl;
    }

    return 0;
}