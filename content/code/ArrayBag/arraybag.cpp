#include "arraybag.hpp"

template<class T>
ArrayBag<T>::ArrayBag(): item_count_{0}{ } // end default constructor

template<class T>
int ArrayBag<T>::getCurrentSize() const{
    return item_count_;
} // end getCurrentSize

template<class T>
bool ArrayBag<T>::isEmpty() const {
    return (item_count_ == 0);
} // end isEmpty

template<class T>
bool ArrayBag<T>::add(const T& new_entry)
{
    bool has_room_to_add = (item_count_ < DEFAULT_CAPACITY);
    if (has_room_to_add) {
        items_[item_count_] = new_entry;
        item_count_++;
    } // end if
    return has_room_to_add;
} // end add

template<class T>
bool ArrayBag<T>::remove(const T& an_entry) {
    int located_index = getIndexOf(an_entry);
    bool can_remove_item = !isEmpty() && (located_index > -1);
    if (can_remove_item) {
        item_count_--;
        items_[located_index] = items_[item_count_]; // copy last item in place of
    // item to be removed
    } // end if
    return can_remove_item;
} // end remove

template<class T>
int ArrayBag<T>::getFrequencyOf(const T& an_entry) const {
    int frequency = 0;
    int current_index = 0; // array index currently being inspected
    while (current_index < item_count_) {
        if (items_[current_index] == an_entry) {
            frequency++;
        } // end if
        current_index ++; // increment to next entry
    } // end while
    return frequency;
} // end getFrequencyOf

template<class T>
std::vector<T> ArrayBag<T>::toVector() const {
    std::vector<T> bag_contents;
    for (int i = 0; i < item_count_; i++)
        bag_contents.push_back(items_[i]);
    return bag_contents;
} // end toVector

template<class T>
int ArrayBag<T>::getIndexOf(const T& target) const {
    bool found = false;
    int result = -1;
    int search_index = 0;
    // If the bag is empty, item_count_ is zero, so loop is skipped
    while (!found && (search_index < item_count_)) {
        if (items_[search_index] == target) {
            found = true;
            result = search_index;
        }
        else {
            search_index ++;
        } // end if
    } // end while
    return result;
} // end getIndexOf

template<class T>
void ArrayBag<T>::clear() {
    item_count_ = 0;
} // end clear

template<class T>
bool ArrayBag<T>::contains(const T& an_entry) const {
    return getIndexOf(an_entry) > -1;
} // end contains
