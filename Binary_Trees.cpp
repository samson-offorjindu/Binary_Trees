#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    // insert a new node with the given data into the tree
    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;

        if (root == NULL) {
            root = newNode;
        }
        else {
            Node* current = root;
            Node* parent;

            while (true) {
                parent = current;
                if (data < current->data) {
                    current = current->left;
                    if (current == NULL) {
                        parent->left = newNode;
                        break;
                    }
                }
                else {
                    current = current->right;
                    if (current == NULL) {
                        parent->right = newNode;
                        break;
                    }
                }
            }
        }
    }

    // search for a node with the given data in the tree
    bool search(int data) {
        Node* current = root;

        while (current != NULL) {
            if (current->data == data) {
                return true;
            }
            else if (data < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }

    // perform in-order traversal of the tree (left-root-right)
    void inOrder(Node* current) {
        if (current != NULL) {
            inOrder(current->left);
            cout << current->data << " ";
            inOrder(current->right);
        }
    }

    // perform pre-order traversal of the tree (root-left-right)
    void preOrder(Node* current) {
        if (current != NULL) {
            cout << current->data << " ";
            preOrder(current->left);
            preOrder(current->right);
        }
    }

    // perform post-order traversal of the tree (left-right-root)
    void postOrder(Node* current) {
        if (current != NULL) {
            postOrder(current->left);
            postOrder(current->right);
            cout << current->data << " ";
        }
    }

    // find the minimum value in the tree
    int findMin(Node* current) {
        if (current->left == NULL) 
            return current->data;
        
        else 
            return findMin(current->left);
        
    }

    // find the maximum value in the tree
    int findMax(Node* current) {
        if (current->right == NULL) 
            return current->data;
        
        else 
            return findMax(current->right);
        
    }

    void display_q() {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                Node* current = q.front();
                q.pop();
                cout << current->data << " ";

                if (current->left != NULL) 
                    q.push(current->left);
                
                if (current->right != NULL) 
                    q.push(current->right);
                
            }
            cout << endl;
        }
    }

    void display() {
        cout << endl;
        display(root, 0);
        cout << endl;
    }

    void display(Node* current, int level) {
        if (current != NULL) {
            display(current->right, level + 1);

            for (int i = 0; i < level; i++) {
                cout << "        ";
            }

            cout << current->data << endl;
            display(current->left, level + 1);
        }
    }
};

int main() {
    BinaryTree tree;

    tree.insert(50);
    tree.insert(540);
    tree.insert(60);
    tree.insert(43);
    tree.insert(12);
    tree.insert(11);
    tree.insert(59);
    tree.insert(38);
    tree.insert(40);

    tree.display();

    EXIT_SUCCESS;
}
