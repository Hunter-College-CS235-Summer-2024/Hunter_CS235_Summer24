#ifndef BST_H_
#define BST_H_
#include "BinaryNode.hpp"
#include "Visitor.hpp"
#include <stack>
#include <memory>

template<class T>
class BST {
    public:
        BST();
        BST(const BST<T>& tree);
        BST(BST<T>&& tree);
        ~ BST();
        bool isEmpty() const;
        size_t getHeight() const;
        // TODO: size_t getNumberOfNodes() const;
        void add(const T& new_item);
        bool remove(const T& new_item);
        // TODO: find(const T& item) const;
        void clear();
        // TODO: void preorderTraverse(Visitor<T>& visit) const;
        void inorderTraverse(Visitor<T>& visit) const;
        // TODO: void postorderTraverse(Visitor<T>& visit) const;
        BST<T>& operator= (const BST<T>& rhs);
        BST<T>& operator= (BST<T>&& rhs);
    private:
        std::shared_ptr<BinaryNode<T>> root_ptr_;
        // helper functions
        std::shared_ptr<BinaryNode<T>> copyTree(const std::shared_ptr<BinaryNode<T>> old_tree_root_ptr) const;
        void destroyTree(std::shared_ptr<BinaryNode<T>> sub_tree_ptr);
        size_t getHeightHelper(std::shared_ptr<BinaryNode<T>> sub_tree_ptr) const;
        auto placeNode(std::shared_ptr<BinaryNode<T>> subtree_ptr, std::shared_ptr<BinaryNode<T>> new_node_ptr);
        std::shared_ptr<BinaryNode<T>> removeValue(std::shared_ptr<BinaryNode<T>> subtree_ptr, const T target, bool& success);
        std::shared_ptr<BinaryNode<T>> removeNode(std::shared_ptr<BinaryNode<T>> node_ptr);
        std::shared_ptr<BinaryNode<T>> removeLeftmostNode(std::shared_ptr<BinaryNode<T>> nodePtr, T& inorderSuccessor);
};

#include "BST.cpp"
#endif
