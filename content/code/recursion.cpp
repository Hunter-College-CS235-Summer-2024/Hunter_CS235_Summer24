#include <iostream>
#include <vector>
#include <stdexcept>

std::string reverseString(std::string str){
    if (str.length() == 0) {
        return "";
    }
    return reverseString(str.substr(1)) + str[0];
}

template <class T>
size_t binarySearch(const std::vector<T>& container, const T& item, size_t left, size_t right) {
    if (left > right) {
        throw std::out_of_range("The `item` doesn't exist in the `container`.");
    }
    size_t mid = left + ((right-left) / 2);
    
    if (container[mid] == item) {
        return mid;
    }
    
    if (item < container[mid]) {
        return binarySearch(container,item,0,mid-1);
    }
    
    return binarySearch(container,item,mid+1,right);
}

template <class T>
std::ostream& operator<<(std::ostream& os, std::vector<T> container) {
    for (auto i: container) {
        os << i << " ";
    }
    return os;
}

int main() {
    std::string query = "badaS";
    std::cout << reverseString(query) << std::endl;

    std::vector<int> sorted = {10,20,30,40,50,60,70,80,90};
    std::cout << sorted << std::endl;
    try {
        std::cout << binarySearch(sorted,100,0,sorted.size()-1) << std::endl;
    }
    catch(const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Index of `60`: " << binarySearch(sorted,60,0,sorted.size()-1) << std::endl;
}
