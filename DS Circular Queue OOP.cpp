#include <iostream>
using namespace std;

class CircularQueue {
private:
    int queue[100];
    int front;
    int rear;
    int Maxsize;

public:
    CircularQueue(int maxSize) : front(-1), rear(-1), Maxsize(maxSize) {}

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % Maxsize == front;
    }

    bool enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return false;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % Maxsize;
        }
        queue[rear] = element;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return false;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % Maxsize;
        }
        return true;
    }

    int frontElement() {
       return queue[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        int i = front;
        do {
            cout << "Queue Element: " << queue[i] <<" ";
            i = (i + 1) % Maxsize;
        } while (i != (rear + 1) % Maxsize);
        cout<<endl ;
    }
};

int main() {
    int maxSize;
    cout << "Enter the maximum size of the circular queue: ";
    cin >> maxSize;

    CircularQueue myQueue(maxSize);

    int choice, element;

    do {
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Front"<<endl;
        cout << "4. Display"<<endl;
        cout << "5. Exit"<<endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                myQueue.enqueue(element);
                break;
            case 2:
                if (myQueue.dequeue()) {
                    cout << "Element dequeued."<<endl;
                }
                break;
            case 3:
                cout << "Front element: " << myQueue.frontElement() << endl;
                break;
            case 4:
                myQueue.display();
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
