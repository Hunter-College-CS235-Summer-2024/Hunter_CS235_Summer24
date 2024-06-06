/**
 * Author: Sadab Hafiz
 * Date: 06/04/2024
 * Description: This is the implementation of the ArrayBag class
 */
#include "ArrayBag.hpp"

template<class T>
ArrayBag<T>::ArrayBag(): item_count_{0} { }

template<class T>
int ArrayBag<T>::getCurrentSize() const {
    return item_count_;
}

template<class T>
bool ArrayBag<T>::isEmpty() const {
    return (item_count_ == 0);
}

template<class T>
bool ArrayBag<T>::add(const T& new_entry) {
    bool has_room_to_add = (item_count_ < DEFAULT_CAPACITY);
    // add new_entry to the back of the array if there is space
    if (has_room_to_add) {
        items_[item_count_] = new_entry;
        item_count_++;
    }
    return has_room_to_add;
}

template<class T>
bool ArrayBag<T>::remove(const T& an_entry) {
    int located_index = getIndexOf(an_entry);
    bool can_remove_item = !isEmpty() && (located_index > -1);
    // swap the item to be removed with the last item in the array
    // decrement the item_count making the last item inaccessible by the user
    if (can_remove_item) {
        item_count_--;
        items_[located_index] = items_[item_count_]; 
    } 
    return can_remove_item;
} 

template<class T>
int ArrayBag<T>::getFrequencyOf(const T& an_entry) const {
    int frequency = 0;
    // iterate through the items in the items_ array
    for (int curr: items_) {
        // increment the frequency of the item if it is found
        if (curr == an_entry) {
            frequency++;
        }
    }
    return frequency;
}

template<class T>
std::vector<T> ArrayBag<T>::toVector() const {
    std::vector<T> bag_contents;
    // add each item of the items_ array to bag_contents
    for (int item: items_) {
        bag_contents.push_back(item);
    }
    return bag_contents;
}

template<class T>
int ArrayBag<T>::getIndexOf(const T& target) const {
    // iterate through the items in the items_ array
    for (int i = 0; i < item_count_; i++) {
        // return i if the ith index is the target
        if (items_[i] == target) {
            return i;
        }
    }
    // return -1 to indicate that the target is not found
    return -1;
}

template<class T>
void ArrayBag<T>::clear() {
    item_count_ = 0;
}

template<class T>
bool ArrayBag<T>::contains(const T& an_entry) const {
    // if getIndexOf returns an index of 0 or positive index, the item is found 
    return getIndexOf(an_entry) > -1;
}

