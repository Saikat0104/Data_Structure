#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a Sentence: ";
    getline(cin, input);

    int vowelCount = 0;

    for (int i = 0; i < input.length(); i++) {
        char c = tolower(input[i]);  // we  have Convert it to lowercase for case-insensitive

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelCount++;
        }
    }

    cout << "Vowels appeared " << vowelCount << " times." << endl;

    return 0;
}
