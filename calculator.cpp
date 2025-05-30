#include <iostream>
using namespace std;

class calculator {
    private:
    int number_one, number_two;
    string option;

    public:
    void ShowOperations() {
        cout << "-----------Calculator-----------" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
    }

    void numbersInput() {
        cout << endl;
        cout << "Enter Number One: ";
        cin >> number_one;
        cout << "Enter Number Two: ";
        cin >> number_two;
        cout << endl;
    }

    void optionInput() {
        cout << "Enter option (1,2 or +, x etc): ";
        cin >> option;
        cout << endl;
    }

    void doWork() {
        if(option == "1" || option == "+") {
            int result = number_one + number_two;
            cout << number_one << " + " << number_two << " = " << result << endl;
        }
        else if(option == "2" || option == "-") {
            int result = number_one - number_two;
            cout << number_one << " - " << number_two << " = " << result << endl;
        }
        else if(option == "3" || option == "x") {
            int result = number_one * number_two;
            cout << number_one << " x " << number_two << " = " << result << endl;
        }
        else if(option == "4" || option == "/") {
            int result = number_one / number_two;
            if(number_one != 0) {
                cout << number_one << " / " << number_two << " = " << result << endl;
            } else {
                cout << "Can't divide by Zero!" << endl;
            }
        }
    }
};

int main() {
    calculator clc;
    clc.ShowOperations();
    clc.numbersInput();
    clc.optionInput();
    clc.doWork();
}