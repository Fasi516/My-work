#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Binary Search Tree Implementation
class BSTNode {
public:
    int value;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    BSTNode* root;

    BSTNode* insert(BSTNode* node, int value) {
        if (node == nullptr) {
            return new BSTNode(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool isComplete(BSTNode* root, int index, int numberNodes) {
        if (root == nullptr) {
            return true;
        }
        if (index >= numberNodes) {
            return false;
        }
        return isComplete(root->left, 2 * index + 1, numberNodes) &&
               isComplete(root->right, 2 * index + 2, numberNodes);
    }

    int countNodes(BSTNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool isCompleteBinaryTree() {
        int numberNodes = countNodes(root);
        return isComplete(root, 0, numberNodes);
    }
};

// Min-Heap Implementation
class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMin() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    void deleteMin() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

// Main Function
int main() {
    // Binary Search Tree
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(6);
    bst.insert(15);
    bst.insert(3);
    bst.insert(8);
    bst.insert(12);
    bst.insert(17);

    if (bst.isCompleteBinaryTree()) {
        cout << "The tree is a complete binary tree." << endl;
    } else {
        cout << "The tree is not a complete binary tree." << endl;
    }

    // Min-Heap
    MinHeap minHeap;
    vector<int> incidents = {20, 5, 17, 8, 2, 11};

    for (int severity : incidents) {
        minHeap.insert(severity);
    }

    cout << "Min severity: " << minHeap.getMin() << endl; // Should print 2
    minHeap.deleteMin();
    cout << "Min severity after addressing: " << minHeap.getMin() << endl; // Should print 5

    cout << "Current heap: ";
    minHeap.printHeap();

    return 0;
}
