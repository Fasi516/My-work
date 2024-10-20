#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BinarySearchTree {
private:
    TreeNode* root;

    // Helper function to insert a value into the BST
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    // Helper function to check if the binary tree is complete
    bool isCompleteBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        // Perform level order traversal
        queue<TreeNode*> q;
        q.push(root);

        bool end = false;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                end = true;
            } else {
                if (end) {
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Insert a value into the BST
    void insert(int val) {
        root = insert(root, val);
    }

    // Check if the tree is a complete binary tree
    bool isCompleteBinaryTree() {
        return isCompleteBinaryTree(root);
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(6);
    bst.insert(15);
    bst.insert(3);
    bst.insert(8);
    bst.insert(12);
    bst.insert(17);

    cout << "Is the tree a complete binary tree? " 
         << (bst.isCompleteBinaryTree() ? "Yes" : "No") 
         << endl;

    return 0;
}
