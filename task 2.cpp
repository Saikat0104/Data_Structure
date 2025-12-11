#include <iostream>
#include <string.h>
using namespace std;


int main()
{
    cin.clear();
    cin.ignore(100,'\n');  //i must put cin.clear,ignore before declaring string,or else error will come
    string input1, input2;


    cout << "Enter the first string: ";
    getline(cin, input1);

    cout << "Enter the second string: ";
    getline(cin, input2);

   string merged = input1 + " " + input2;
    cout << "Merged String: " <<merged << endl;


    return 0;
}
