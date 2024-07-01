template<class T>
BinaryNode<T>::BinaryNode(const T& an_item) : item_{an_item}, left_{nullptr}, right_{nullptr} { }

template<class T>
BinaryNode<T>::BinaryNode(const T& an_item, std::shared_ptr<BinaryNode<T>> left, std::shared_ptr<BinaryNode<T>> right) :
                            item_{an_item}, left_{left}, right_{right} { }

template<class T>
void BinaryNode<T>::setItem(const T& an_item) {
    item_ = an_item;
}

template<class T>
T BinaryNode<T>::getItem() const{
    return item_;
}

template<class T>
bool BinaryNode<T>::isLeaf() const{
    return (left_ == nullptr) && (right_ == nullptr);
}

template<class T>
auto BinaryNode<T>::getLeftChildPtr() const {
    return left_;
}

template<class T>
auto BinaryNode<T>::getRightChildPtr() const {
    return right_;
}

template<class T>
void BinaryNode<T>::setLeftChildPtr(std::shared_ptr<BinaryNode<T>> left_ptr) {
    left_ = left_ptr;
}

template<class T>
void BinaryNode<T>::setRightChildPtr(std::shared_ptr<BinaryNode<T>> right_ptr) {
    right_ = right_ptr;
}
