/**
 * Author: Sadab Hafiz
 * Date: 06/04/2024
 * Description: This is the interface for ArrayBag class
 */
#pragma once

#include <vector>

template<class T>
class ArrayBag
{
    public:
        /**
         * Default Constructor
         * @post Creates an ArrayBag object with item_count_ initialized to 0
         */
        ArrayBag();
        /**
         * @return The current number of items in the ArrayBag
         */
        int getCurrentSize() const;
        /**
         * @return True if the ArrayBag is empty, false otherwise
         */
        bool isEmpty() const;
        /**
         * @param new_entry The new item to be added to the ArrayBag
         * @return True if the addition was successful, false otherwise
         */
        bool add(const T& new_entry);
        /**
         * @param an_entry The item to be removed from the ArrayBag
         * @return True if the removal was successful, false otherwise
         */
        bool remove(const T& an_entry);
        /**
         * @post Clears all items from the ArrayBag
         */
        void clear();
        /**
         * @param an_entry The item to check for in the ArrayBag
         * @return True if the item is found, false otherwise
         */
        bool contains(const T& an_entry) const;
        /**
         * @param an_entry The item to count occurrences of in the ArrayBag
         * @return The number of times the item appears in the ArrayBag
         */
        int getFrequencyOf(const T& an_entry) const;
        /**
         * @return A vector containing all the items in the ArrayBag
         */
        std::vector<T> toVector() const;  
    private:
        static const int DEFAULT_CAPACITY = 200;
        T items_[DEFAULT_CAPACITY];
        int item_count_;
        /**
         * @param target The item to find in the ArrayBag
         * @return The index of the target item in the ArrayBag if found, -1 otherwise
         */
        int getIndexOf(const T& target) const;
};
#include "arraybag.cpp"
