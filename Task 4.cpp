
#include <iostream>
#include <string>

int main() {
    std::string a;
    std::string b;

    std::cout << "Enter the first string: ";
    std::getline(std::cin, a);

    std::cout << "Enter the second string: ";
    std::getline(std::cin, b);

    if (a == b) {
        std::cout << "Same" << std::endl;
    } else {
        std::cout << "Not Same" << std::endl;
    }

    return 0;
}
