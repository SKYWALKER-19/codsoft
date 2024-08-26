 #include <iostream>
#include <iomanip> // For formatting output

int main() {
    double num1, num2;
    char operation;
    double result;

    // Prompt the user for input
    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;

    // Perform the operation based on user's choice
    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << std::fixed << std::setprecision(2) << num1 << " + " << num2 << " = " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << std::fixed << std::setprecision(2) << num1 << " - " << num2 << " = " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << std::fixed << std::setprecision(2) << num1 << " * " << num2 << " = " << result << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                std::cout << "Result: " << std::fixed << std::setprecision(2) << num1 << " / " << num2 << " = " << result << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operation." << std::endl;
            break;
    }

    return 0;
}
