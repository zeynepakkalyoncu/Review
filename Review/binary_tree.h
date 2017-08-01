#ifndef binary_tree_h
#define binary_tree_h

#include "binary_node.h"

#include <queue>

template <typename T>
class BinaryTree {
private:
    BinaryNode<T>* _root;
public:
    BinaryTree() : _root(NULL) {}
    BinaryTree(BinaryNode<T>* root) : _root(root) {}
    
    // time: O(n) space: O()
    int nodeDepth(BinaryNode<T>* node) {
        if (node.isRoot()) return 0;
        else return 1 + nodeDepth(node->_parent);
    }
    
    // time: O(n) space: O()
    int nodeHeight(BinaryNode<T>* node) {
        
    }
    
    // time: O() space: O()
    void preorderTraversal(BinaryNode<T>* node) {
        if (node) {
            std::cout << node->data << " ";
            preorderTraversal(node->_left);
            preorderTraversal(node->_right);
        }
    }
    
    // time: O() space: O()
    void inorderTraversal(BinaryNode<T>* node) {
        if (node) {
            preorderTraversal(node->_left);
            std::cout << node->data << " ";
            preorderTraversal(node->_right);
        }
    }
    
    // time: O() space: O()
    void postorderTraversal(BinaryNode<T>* node) {
        if (node) {
            preorderTraversal(node->_left);
            preorderTraversal(node->_right);
            std::cout << node->data << " ";
        }
    }
    
    // time: O(n) space: O(n)
    void levelorderTraversalWithQueue(BinaryNode<T>* node) {
        queue<BinaryNode<T>* > q;
        q.push(node);
        
        while (!q.empty()) {
            BinaryNode<T>* curNode = q.pop();
            q.push(curNode->_left); q.push(curNode->_right);
            std::cout << curNode->_data << " ";
        }
        
        std::cout << std::endl;
    }
    
    // time: O(n) space: O(1) - skewed tree
    void printLevel(BinaryNode<T>* node, int level) {
        if (node) {
            if (level == 1) std::cout << node->_data << " ";
            else if (level > 1) {
                printLevel(node->_left, level - 1);
                printLevel(node->_height, level - 1);
            }
        }
    }
    
    // time: O(n^2) space: O(1) - skewed tree
    void levelorderTraversalWithHelper(BinaryNode<T>* node) {
        int height = nodeHeight(node);
        for (int i = 0; i < height; i++) {
            printLevel(node, i);
        }
    }
    
    // time: O() space: O()
    bool isBSTMinMax(BinaryNode<T>* node, int min, int max) {
        
    }
    
    // time: O(n) space: O(1)
    bool isBSTInOrder(BinaryNode<T>* node) {
        static BinaryNode<T>* previous = NULL;
        
        if (node) {
            if (!isBSTInOrder(node->_left)) return false;
            if (previous && (node->_data > previous->_data)) return false;
            
            previous = node;
            
            return isBSTInOrder(node->right);
        }
    }
    
    // time: O() space: O()
    int size() {
        
    }
    
    // time: O() space: O()
    void swap(BinaryNode<T>* node1, BinaryNode<T>* node2) {
        
    }
    
    // time: O() space: O()
    void replace(T oldValue, T newValue) {
        
    }
    
    ~BinaryTree() {
        
    }
};

#endif