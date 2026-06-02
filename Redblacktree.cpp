#include <iostream>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
struct node {
    node* parent = nullptr, * left = nullptr, * right = nullptr;
    int val;
    char color; 
};
class rbtree {
private:
    node* root; 
    int n;      
void leftRotate(node* x) 
{
        node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
}
void rightRotate(node* x) 
{
        node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr)
            y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;
}
void balance(node* z) 
{
        while (z->parent != nullptr && z->parent->color == 'R') {
            node* grandparent = z->parent->parent;
            if (z->parent == grandparent->left) {
                node* uncle = grandparent->right;
                if (uncle != nullptr && uncle->color == 'R') {
                    z->parent->color = 'B';
                    uncle->color = 'B';
                    grandparent->color = 'R';
                    z = grandparent;
                }
                else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = 'B';
                    grandparent->color = 'R';
                    rightRotate(grandparent);
                }
            }
            else {
                node* uncle = grandparent->left;
                if (uncle != nullptr && uncle->color == 'R') {
                    z->parent->color = 'B';
                    uncle->color = 'B';
                    grandparent->color = 'R';
                    z = grandparent;
                }
                else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = 'B';
                    grandparent->color = 'R';
                    leftRotate(grandparent);
                }
            }
        }
        root->color = 'B';
}
public:
    rbtree() : root(nullptr), n(0) 
    {}
    void find(int value) const 
    {
        node* current = root;
        while (current != nullptr) {
            if (value == current->val) {
                cout << "Value " << value << " exists in the tree." << endl;
                return;
            }
            else if (value < current->val) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        cout << "Value " << value << " does not exist!" << endl;
    }
    void insert(int value) 
    {
        node* z = new node;
        z->val = value;
        z->color = 'R';
        node* y = nullptr;
        node* x = root;
        while (x != nullptr) {
            y = x;
            if (z->val < x->val)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == nullptr)
            root = z; 
        else if (z->val < y->val)
            y->left = z;
        else
            y->right = z;
        balance(z); 
        n++;
    }
    void levelOrderTraversal() const 
    {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }
        std::queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            node* current = q.front();
            q.pop();

            cout << "Value: " << current->val << ", Color: " << current->color << endl;

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }
};
int main() {
    rbtree tree;
    tree.insert(10);
    tree.insert(201);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(1);
    tree.insert(13);
    tree.insert(90);
    tree.insert(7);
    tree.insert(3);
    tree.insert(50);
    tree.insert(101);
    tree.insert(1010);
    tree.insert(17);
    tree.insert(22);
    cout << "Level Order Traversal:" << endl;
    tree.levelOrderTraversal();
    int temp = 15;
    tree.find(temp);
    temp = 30;
    tree.find(temp);
    return 0;
}
