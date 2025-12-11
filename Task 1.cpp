#include <iostream>

int main() {
    int array_1[] = {8, 4, 6, 1, 6, 9, 6, 1, 9, 8};
    int size = sizeof(array_1) / sizeof(array_1[0]);


    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        count[array_1[i]]++;
    }

    for (int i = 0; i < 10; i++) {
        if (count[i] > 0) {
            std::cout << i << " occurs = " << count[i] << " times" << std::endl;
        }
    }

    return 0;
}

