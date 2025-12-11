#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int student_id;
    std::string name;
    float cgpa;
    Student* left;
    Student* right;

    Student(int id, const std::string& n, float g) : student_id(id), name(n), cgpa(g), left(nullptr), right(nullptr) {}
};

class StudentBST {
private:
    Student* root;

public:
    StudentBST() : root(nullptr) {}

    void insert(int student_id, const std::string& name, float cgpa) {
        root = _insert(root, student_id, name, cgpa);
    }

    Student* _insert(Student* root, int student_id, const std::string& name, float cgpa) {
        if (root == nullptr) {
            return new Student(student_id, name, cgpa);
        }
        if (student_id < root->student_id) {
            root->left = _insert(root->left, student_id, name, cgpa);
        }
        else if (student_id > root->student_id) {
            root->right = _insert(root->right, student_id, name, cgpa);
        }
        return root;
    }

    Student* search(int student_id) {
        return _search(root, student_id);
    }

    Student* _search(Student* root, int student_id) {
        if (root == nullptr || root->student_id == student_id) {
            return root;
        }
        if (student_id < root->student_id) {
            return _search(root->left, student_id);
        }
        return _search(root->right, student_id);
    }

    void deleteNode(int student_id) {
        root = _delete(root, student_id);
    }

    Student* _delete(Student* root, int student_id) {
        if (root == nullptr) {
            return root;
        }
        if (student_id < root->student_id) {
            root->left = _delete(root->left, student_id);
        }
        else if (student_id > root->student_id) {
            root->right = _delete(root->right, student_id);
        }
        else {
            if (root->left == nullptr) {
                Student* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Student* temp = root->left;
                delete root;
                return temp;
            }
            root->student_id = minValueNode(root->right)->student_id;
            root->right = _delete(root->right, root->student_id);
        }
        return root;
    }

    Student* minValueNode(Student* node) {
        Student* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
};

int main() {
    StudentBST studentTree;
    studentTree.insert(101, "fahim", 3.6);
    studentTree.insert(102, "sakib", 3.7);
    studentTree.insert(103, "tamim", 3.8);

    Student* searchResult = studentTree.search(102);
    if (searchResult) {
        std::cout << "Student found: ID=" << searchResult->student_id << ", Name=" << searchResult->name << ", CGPA=" << searchResult->cgpa << std::endl;
    }
    else {
        std::cout << "Student not found" << std::endl;
    }

    studentTree.deleteNode(102);

    searchResult = studentTree.search(102);
    if (searchResult) {
        std::cout << "Student found: ID=" << searchResult->student_id << ", Name=" << searchResult->name << ", CGPA=" << searchResult->cgpa << std::endl;
    }
    else {
        std::cout << "Student not found after deletion" << std::endl;
    }

    return 0;
}
