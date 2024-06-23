/**
 * @file LinkedList.cpp
 * @author Sadab Hafiz
 * @brief Implementation file for a Singly LinkedList class
 * @date 2024-06-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "LinkedList.hpp"

template <class T>
LinkedList<T>::LinkedList() : head_(nullptr), tail_(nullptr), item_count_(0) {}

template <class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    head_ = nullptr;
    tail_ = nullptr;
    item_count_ = 0;

    Node* current = other.head_;
    while (current != nullptr) {
        insert(current->item_, item_count_);
        current = current->next_;
    }
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this != &other) {
        clear();
        Node* current = other.head_;
        while (current != nullptr) {
            insert(current->item_, item_count_);
            current = current->next_;
        }
    }
    return *this;
}

template <class T>
size_t LinkedList<T>::getSize() const {
    return item_count_;
}

template <class T>
bool LinkedList<T>::isEmpty() const {
    return item_count_ == 0;
}

template <class T>
void LinkedList<T>::clear() {
    Node* current = head_;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next_;
        delete temp;
    }
    head_ = nullptr;
    tail_ = nullptr;
    item_count_ = 0;
}

template <class T>
void LinkedList<T>::insert(const T& item, size_t position) {
    if (position > item_count_) {
        position = item_count_;
    }

    Node* new_node = new Node{item, nullptr};

    if (item_count_ == 0) {
        head_ = new_node;
        tail_ = new_node;
    }
    else if (position == 0) {
        new_node->next_ = head_;
        head_ = new_node;
    }
    else {
        Node* current = head_;
        for (size_t i = 0; i < position - 1; i++) {
            current = current->next_;
        }
        new_node->next_ = current->next_;
        current->next_ = new_node;
        if (position == item_count_) {
            tail_ = new_node;
        }
    }

    item_count_++;
}

template <class T>
bool LinkedList<T>::remove(const T& item) {
    Node* current = head_;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->item_ == item) {
            if (current == head_) {
                head_ = current->next_;
            }
            else {
                prev->next_ = current->next_;
            }
            if (current == tail_) {
                tail_ = prev;
            }
            delete current;
            item_count_--;
            return true;
        }

        prev = current;
        current = current->next_;
    }

    return false;
}

template <class T>
T& LinkedList<T>::operator[](size_t index) {
    if (index >= item_count_) {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head_;
    for (size_t i = 0; i < index; i++) {
        current = current->next_;
    }
    return current->item_;
}

