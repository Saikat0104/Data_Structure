#include <iostream>
using namespace std;

class Stack {
private:
    int stack[100];
    int top;
    int Maxsize;

public:
    Stack(int maxSize) : top(0), Maxsize(maxSize) {
       
    }

    bool isEmpty() {
        return top == 0;
    }

    bool isFull() {
        return top == Maxsize;
    }

    bool push(int Element) {
        if (isFull()) {
            cout << "Stack Overflow "<<endl;
            return false;
        }
        stack[top++] = Element;
        return true;
    }

    bool pop() {
        if (isEmpty()) {
            cout << "Stack is Empty "<<endl;
            return false;
        }
        top--;
        return true;
    }

    int topElement() {
        return stack[top - 1];  
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty "<<endl;
            return;
        }
        for (int i = top - 1; i >= 0; i--) {
            cout << "Stack Element: " << stack[i] << " ";
        }
    }
};

int main() {
    int maxSize;
    cout << "Enter the maximum size of the stack: ";
    cin >> maxSize;

    Stack myStack(maxSize);

    int choice, element;

    do {
        cout << "1. Push"<<endl;
        cout << "2. Pop"<<endl;
        cout << "3. Top"<<endl;
        cout << "4. Display"<<endl;
        cout << "5. Exit"<<endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> element;
                myStack.push(element);
                break;
            case 2:
                if (myStack.pop()) {
                    cout << "Element popped."<<endl;
                }
                break;
            case 3:
                if (!myStack.isEmpty()) {
                    cout << "Top element: " << myStack.topElement() << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            case 4:
                myStack.display();
                break;
            case 5:
                cout << "Exiting the program."<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again."<<endl;
        }
    } while (choice != 5);

    return 0;
}
