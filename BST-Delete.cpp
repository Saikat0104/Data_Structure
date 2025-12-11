#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct bin_tree
{
    bin_tree *left, *right;
    int data;
}*nodebst;

nodebst makenode(int value)
{
    nodebst newnode = new bin_tree;
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

nodebst insert_node(nodebst ptr, int value)
{
    if(ptr == NULL)
    {
        ptr = makenode(value);
    }
    else if(value > ptr->data)
    {
        ptr->right = insert_node(ptr->right, value);
    }
    else if(value < ptr->data)
    {
        ptr->left = insert_node(ptr->left, value);
    }
    return ptr;
}

nodebst search_node(nodebst ptr, int value)
{
    if(ptr == NULL)
    {
        return NULL;
    }
    else if(ptr->data == value)
    {
        return ptr;
    }
    else if(ptr->data < value)
    {
        return search_node(ptr->right, value);
    }
    else if(ptr->data > value)
    {
        return search_node(ptr->left, value);
    }
}

void inorder(nodebst ptr)
{
    if(ptr != NULL)
    {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

void preorder(nodebst ptr)
{
    if(ptr != NULL)
    {
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(nodebst ptr)
{
    if(ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
    }
}

nodebst minValueNode(nodebst node) {
    nodebst current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

nodebst deleteNode(nodebst root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            nodebst temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            nodebst temp = root->left;
            delete root;
            return temp;
        }
        nodebst temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    nodebst root = NULL, temp;
    int value, n, x;
    cout << "Enter number of data: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        temp = root;
        if (root == NULL)
            root = insert_node(root, value);
        else
            temp = insert_node(temp, value);
    }

    while(1)
    {
        cout << "Enter option :" << endl;
        cout << "1. Inorder " << endl;
        cout << "2. Preorder " << endl;
        cout << "3. Postorder " << endl;
        cout << "4. Search " << endl;
        cout << "5. Delete " << endl;
        cout << "6. Insert " << endl;
        cin >> x;

        switch(x)
        {
            case 1:
                {
                    cout << "Inorder: ";
                    inorder(root);
                    cout << endl;
                }
                break;
            case 2:
                {
                    cout << "Preorder: ";
                    preorder(root);
                    cout << endl;
                }
                break;
            case 3:
                {
                    cout << "Postorder: ";
                    postorder(root);
                    cout << endl;
                }
                break;
            case 4:
                {
                    cout << "Enter value to search: ";
                    cin >> value;
                    nodebst a;
                    a = search_node(root, value);
                    if (a == NULL)
                        cout << "Not Found!!" << endl;
                    else
                        cout << a->data << " Found!!" << endl;
                }
                break;
            case 5:
                {
                    cout << "Enter value to delete: ";
                    cin >> value;
                    root = deleteNode(root, value);
                    cout << value << " deleted!" << endl;
                }
                break;
            case 6:
                {
                    temp = root;
                    cout << "Enter value to insert: ";
                    cin >> value;
                    temp = insert_node(temp, value);
                }
                break;
            default :
                return 0;
        }
    }
}
