#include <iostream>
#include <string>

int function(int digit1, int digit2) { return digit1 + digit2 + 177; }

int SafeIntCin(std::string msg) {

    int x = 0;

    while (true) {

        std::cout << msg;
        std::cin >> x;

        if (std::cin.fail()) {

            std::cout << "Error! Wrong input! Try it again!" << std::endl;
            std::cin.clear();
            std::cin.ignore(99999, '\n');
        } else {

            std::cout << "Success!" << std::endl;
            std::cin.ignore(99999, '\n');
            break;
        }
    }

    return x;
}

int main() {

    int x = 0;
    int y = 0;
    int result = 0;

    x = SafeIntCin("Enter x: ");
    y = SafeIntCin("Enter y: ");

    result = function(x, y);

    std::cout << "Result is " << result << std::endl;

    return 0;
}
