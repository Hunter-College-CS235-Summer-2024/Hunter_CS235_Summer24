#include "BST.hpp"

template <class T>
BST<T>::BST() {
    root_ptr_ = nullptr;
}

template <class T>
BST<T>::BST(const BST<T>& tree) {
    root_ptr_ = copyTree(tree.root_ptr_);
}

template<class T>
std::shared_ptr<BinaryNode<T>> BST<T>::copyTree(const std::shared_ptr<BinaryNode<T>> old_tree_root_ptr) const {
    std::shared_ptr<BinaryNode<T>> new_tree_ptr;
    if (old_tree_root_ptr != nullptr) {
        new_tree_ptr = std::make_shared<BinaryNode<T>>(old_tree_root_ptr -> getItem(), nullptr, nullptr);
        new_tree_ptr -> setLeftChildPtr(copyTree(old_tree_root_ptr -> getLeftChildPtr()));
        new_tree_ptr -> setRightChildPtr(copyTree(old_tree_root_ptr -> getRightChildPtr()));
    }
    return new_tree_ptr;
}

template<class T>
BST<T>::BST(BST<T>&& tree) {
    root_ptr_ = tree.root_ptr_;
    tree.root_ptr_.reset();
}

template<class T>
BST<T>::~BST() {
    destroyTree(root_ptr_);
}

template<class T>
void BST<T>::destroyTree(std::shared_ptr<BinaryNode<T>> sub_tree_ptr) {
    if (sub_tree_ptr != nullptr) {
        destroyTree(sub_tree_ptr->getLeftChildPtr());
        destroyTree(sub_tree_ptr->getRightChildPtr());
        sub_tree_ptr.reset();
    }
}

template<class T>
bool BST<T>::isEmpty() const {
    return root_ptr_ == nullptr;
}

template<class T>
size_t BST<T>::getHeight() const {
    return getHeightHelper(root_ptr_);
}

template<class T>
size_t BST<T>::getHeightHelper(std::shared_ptr<BinaryNode<T>> sub_tree_ptr) const {
    if (sub_tree_ptr == nullptr) {
        return 0;
    }
    return 1 + std::max(getHeightHelper(sub_tree_ptr->getLeftChildPtr()), getHeightHelper(sub_tree_ptr->getRightChildPtr()));
}

template<class T>
void BST<T>::add(const T& new_item) {
    auto new_node_ptr = std::make_shared<BinaryNode<T>>(new_item);
    root_ptr_ = placeNode(root_ptr_, new_node_ptr);
}

template<class T>
auto BST<T>::placeNode(std::shared_ptr<BinaryNode<T>> subtree_ptr, std::shared_ptr<BinaryNode<T>> new_node_ptr) {
    if (subtree_ptr == nullptr) {
        return new_node_ptr;
    }
    if (subtree_ptr -> getItem() > new_node_ptr -> getItem()) {
        subtree_ptr -> setLeftChildPtr(placeNode(subtree_ptr -> getLeftChildPtr(), new_node_ptr));
    }
    else {
        subtree_ptr->setRightChildPtr(placeNode(subtree_ptr->getRightChildPtr(), new_node_ptr));
    }
    return subtree_ptr;
}

template<class T>
bool BST<T>::remove(const T& target) {
    bool is_successful = false;
    // call may change is_successful
    root_ptr_ = removeValue(root_ptr_, target, is_successful);
    return is_successful;
}

template<class T>
std::shared_ptr<BinaryNode<T>> BST<T>::removeValue(std::shared_ptr<BinaryNode<T>> subtree_ptr, const T target, bool& success) {
    if (subtree_ptr == nullptr) {
        // Not found here
        success = false;
        return subtree_ptr;
    }
    if (subtree_ptr->getItem() == target) {
        // Item is in the root of this subtree
        subtree_ptr = removeNode(subtree_ptr);
        success = true;
        return subtree_ptr;
    }
    if (subtree_ptr->getItem() > target) {
        // Search the left subtree
        subtree_ptr->setLeftChildPtr(removeValue(subtree_ptr
        ->getLeftChildPtr(), target, success));
    }
    else {
        // Search the right subtree
        subtree_ptr->setRightChildPtr(removeValue(subtree_ptr
        ->getRightChildPtr(), target, success));
    }
    return subtree_ptr;
}

template<class T>
std::shared_ptr<BinaryNode<T>> BST<T>::removeNode(std::shared_ptr<BinaryNode<T>> node_ptr) {
    if (node_ptr->isLeaf()) {
        node_ptr.reset();
        return node_ptr;
    }
    else if (node_ptr->getLeftChildPtr() == nullptr) {
        return node_ptr->getRightChildPtr();
    }
    else if (node_ptr->getRightChildPtr() == nullptr) {
        return node_ptr->getLeftChildPtr();
    }
    T new_node_value;
    node_ptr->setRightChildPtr(removeLeftmostNode(node_ptr->getRightChildPtr(), new_node_value));
    node_ptr->setItem(new_node_value);
    return node_ptr;
} 

template<class T>
std::shared_ptr<BinaryNode<T>> BST<T>::removeLeftmostNode(std::shared_ptr<BinaryNode<T>> nodePtr, T& inorderSuccessor) {
    if (nodePtr->getLeftChildPtr() == nullptr) {
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    }
    nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
    return nodePtr;
}

template<class T>
void BST<T>::clear() {
    destroyTree(root_ptr_);
} 

template<class T>
void BST<T>::inorderTraverse(Visitor<T>& visit) const{
    std::stack<std::shared_ptr<BinaryNode<T>>> node_stack;
    std::shared_ptr<BinaryNode<T>> current_ptr = root_ptr_;
    bool done = false;
    while(!done) {
        if(current_ptr != nullptr) {
            node_stack.push(current_ptr);
            //traverse left subtree
            current_ptr = current_ptr->getLeftChildPtr();
        }
        else {
            done = node_stack.empty();
            if(!done) {
                current_ptr = node_stack.top();
                visit(current_ptr->getItem());
                node_stack.pop();
                //traverse right subtree of node just visited
                current_ptr = current_ptr->getRightChildPtr();
            }
        }
    }
}

template<class T>
BST<T>& BST<T>::operator= (const BST<T>& rhs) {
    root_ptr_ = copyTree(rhs.root_ptr_);
    return *this;
}

template<class T>
BST<T>& BST<T>::operator= (BST<T>&& rhs) {
    root_ptr_ = rhs.root_ptr_;
    rhs.root_ptr_.reset();
    return *this;
}
