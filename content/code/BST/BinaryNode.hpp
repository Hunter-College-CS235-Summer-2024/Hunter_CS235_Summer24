#ifndef BinaryNode_H_
#define BinaryNode_H_
#include <memory>

template<class T>
class BinaryNode {
    public:
        BinaryNode() = default;
        BinaryNode(const T& an_item);
        BinaryNode(const T& an_item, std::shared_ptr<BinaryNode<T>> left, std::shared_ptr<BinaryNode<T>> right);
        void setItem(const T& an_item);
        T getItem() const;
        bool isLeaf() const;
        auto getLeftChildPtr() const;
        auto getRightChildPtr() const;
        void setLeftChildPtr(std::shared_ptr<BinaryNode<T>> left_ptr);
        void setRightChildPtr(std::shared_ptr<BinaryNode<T>> right_ptr);
    private:
        T item_;
        std::shared_ptr<BinaryNode<T>> left_;
        std::shared_ptr<BinaryNode<T>> right_;
};

#include "BinaryNode.cpp"
#endif
