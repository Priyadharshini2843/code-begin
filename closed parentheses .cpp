#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string& expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty(); // stack should be empty if balanced
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "{[(])}";
    string expr3 = "((()))";

    cout << expr1 << " => " << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << expr2 << " => " << (isBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;
    cout << expr3 << " => " << (isBalanced(expr3) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}