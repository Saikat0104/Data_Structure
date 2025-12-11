#include <iostream>
#include <string>

std::string encode(const std::string& a, int j) {
    std::string encoded = a;
    for (size_t i = j; i < encoded.length(); i++) {
        if (isalpha(encoded[i])) {
            encoded[i] += 2;
        }
    }
    return encoded;
}

int main() {
    std::string s;
    int j;

    std::cout << "Enter a string: ";
    std::getline(std::cin, s);

    std::cout << "Enter an integer j: ";
    std::cin >> j;

    std::string encoded = encode(s, j);

    std::cout << "Encoded String: " << encoded << std::endl;

    return 0;
}
