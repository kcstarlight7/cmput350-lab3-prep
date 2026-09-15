#include "UniquePtr.h"
#include <utility>
#include <iostream>

struct Base {
    virtual ~Base() = default;
};

struct Derived : Base {};

int main() {
    UniquePtr<int> ptr(new int(5));
    // they test all methods here...
    //UniquePtr<float> ptr2(std::move(ptr));
    //std::cout << ptr.operator bool() << std::endl;
    UniquePtr<Derived> ptr1 = makeUnique<Derived>();
    UniquePtr<Base> ptr2 = std::move(ptr1);
    return 0;
}
