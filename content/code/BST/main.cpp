#include <iostream>
#include <vector>
#include <utility>
#include "BST.hpp"
#include "Visitor.hpp"

template <class T>
std::ostream& operator<<(std::ostream& os, std::vector<T> container) {
    for (auto i: container) {
        os << i << " ";
    }
    return os;
}

template <class T>
class VectorVisitor : public Visitor<T> {
    public:
        virtual void operator()(const T& x) override {
            visited_.push_back(x);
        }
        std::vector<T> getVisited() const {
            return visited_;
        }
    private:
        std::vector<T> visited_;
};

int main() {
    BST<int> a;
    BST<int> b = std::move(a);
    BST<int> c = b;
    std::cout << c.isEmpty() << std::endl;
    c.add(5);
    c.add(1);
    c.add(2);
    std::cout << c.isEmpty() << std::endl;
    a = c;
    c.remove(5);
    c.remove(1);
    c.remove(2);
    std::cout << c.isEmpty() << std::endl;
    std::cout << a.isEmpty() << std::endl;
    VectorVisitor<int> traverser;
    a.inorderTraverse(traverser);
    std::cout << traverser.getVisited() << std::endl;
}
