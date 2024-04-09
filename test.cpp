#include <iostream>
#include <cmath>

int main() {
    double number;
    std::cout << "Enter a number to calculate its square root: ";
    std::cin >> number;

    if (number < 0) {
        std::cout << "Error: Cannot calculate square root of a negative number." << std::endl;
        return 1;
    }

    double squareRoot = sqrt(number);
    std::cout << "Square root of " << number << " is: " << squareRoot << std::endl;

    return 0;
}
