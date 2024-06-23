/**
 * @file LinkedList.hpp
 * @author Sadab Hafiz
 * @brief Header file for a Singly LinkedList class
 * @date 2024-06-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>
#include <stdexcept> 

template <class T>
class LinkedList{
    public:
        /**
        * @brief Default constructor for LinkedList
        * 
        * @post Creates an empty linked list
        */
        LinkedList();

        /**
        * @brief Destructor for LinkedList
        * 
        * @post Cleans up memory allocated for linked list
        */
        ~LinkedList();

        /**
        * @brief Copy constructor for LinkedList
        * 
        * @param other A constant reference to another LinkedList object
        * @post Creates a deep copy of the other LinkedList object
        */
        LinkedList(const LinkedList<T>& other);

        /**
        * @brief Assignment operator for LinkedList
        * 
        * @param other A constant reference to another LinkedList object
        * @return A reference to the current LinkedList object
        * @post Assigns the contents of the other LinkedList object to this LinkedList object
        */
        LinkedList<T>& operator=(const LinkedList<T>& other);

        /**
        * @brief Get the size of the linked list
        * 
        * @return The size of the linked list
        */
        size_t getSize() const;

        /**
        * @brief Check if the linked list is empty
        * 
        * @return True if the linked list is empty, false otherwise
        */
        bool isEmpty() const;

        /**
        * @brief Clear all the items in the linked list
        * 
        * @post Clears all items in the linked list
        */
        void clear();

        /**
        * @brief Insert an item at a given position in the linked list
        * 
        * @param item The item to be inserted
        * @param position The position at which the item should be inserted
        * @post Inserts the item at the specified position in the linked list. 
                If position is greater than the item_count_ insert at the end.
        */
        void insert(const T& item,size_t position);

        /**
        * @brief Remove an item from the linked list
        * 
        * @param item The item to be removed
        * @return True if the item was successfully removed, false otherwise
        * @post Removes the item from the linked list if it exists
        */
        bool remove(const T& item);

        /**
        * @brief Overloaded [] operator to access elements by index
        * 
        * @param index The index of the element to access
        * @return A reference to the element at the specified index
        * @throws std::out_of_range if the index is out of range
        */
        T& operator[](size_t index);

    private:
        struct Node{
            T item_;
            Node* next_;
        };
        Node* head_;
        Node* tail_;
        size_t item_count_;
};

#include "LinkedList.cpp"

